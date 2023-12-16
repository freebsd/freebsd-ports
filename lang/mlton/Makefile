# Because MLton is written in SML, it needs an SML compiler to build.
# It is easiest to use another (earlier) binary version of MLton as
# the SML compiler.  So, this Makefile fetches and installs an
# already-built version of MLton, BOOT_DIST, to use for bootstrapping.
PORTNAME=	mlton
PORTVERSION=	20210816
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES+=	https://github.com/beyert/mlton-freebsd_bootstrap/raw/c7371c1/:bootstrap
DISTFILES+=	${BOOTNAME}.i386-${OPSYS:tl}-13.txz:bootstrap \
		${BOOTNAME}.amd64-${OPSYS:tl}-13.txz:bootstrap \
		${BOOTNAME}.i386-${OPSYS:tl}-12.txz:bootstrap \
		${BOOTNAME}.amd64-${OPSYS:tl}-12.txz:bootstrap

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Optimizing Standard ML compiler
WWW=		http://mlton.org/

LICENSE=	HPND
LICENSE_GROUPS=	COPYFREE OSI
LICENSE_NAME=	Historical Permission Notice and Disclaimer
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake

BOOTNAME=	${BOOTNAMEPREFIX}${PORTNAME}${BOOTNAMESUFFIX}-${BOOTVERSIONPREFIX}${BOOTVERSION}${BOOTVERSIONSUFFIX}
BOOTVERSIONSUFFIX=
BOOTVERSION=	${PORTVERSION}
BOOTOSMAJ=	${OSREL:R}

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		MLTON NATIVE
OPTIONS_SINGLE=			BOOTSTRAP TARGET
OPTIONS_SINGLE_BOOTSTRAP=	MLTON POLYML SMLNJ
OPTIONS_SINGLE_TARGET=		NATIVE

MLTON_DESC=	Bootstrap with MLton (ideal if supported)
NATIVE_DESC=	Use default target for given architecture
POLYML_DESC=	Bootstrap with PolyML
SMLNJ_DESC=	Bootstrap with SML/NJ (can take many hours)

DOCS_BUILD_DEPENDS=		htmldoc:textproc/htmldoc
DOCS_USES=			tex
DOCS_USE=			TEX=latex:build
DOCS_MAKE_ARGS=			MLTON_BINARY_RELEASE_WITH_DOCS=true
DOCS_MAKE_ARGS_OFF=		MLTON_BINARY_RELEASE_WITH_DOCS=false
DOCS_ALL_TARGET=		install-docs all
DOCS_ALL_TARGET_OFF=		all
DOCS_INSTALL_TARGET=		install-docs install
DOCS_INSTALL_TARGET_OFF=	install
MLTON_MAKE_ARGS=		DESTDIR='' \
				LIB=${BOOT_WRKSRC}/lib \
				MLTON_VERSION=${PORTVERSION} \
				PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
				PREFIX=${PREFIX} \
				SML_LIB=${BOOT_WRKSRC}/lib/sml \
				TDOC=${STAGEDIR}${DOCSDIR} \
				TEXM=${STAGEDIR}${EXAMPLESDIR} \
				WITH_GMP_DIR=${PREFIX}
MLTON_MAKE_ARGS_OFF=		DESTDIR='' \
				MLTON_VERSION=${PORTVERSION} \
				PATH=${WRKSRC}/build/bin:${WRKDIR}/bin:${PATH} \
				PREFIX=${PREFIX} \
				WITH_GMP_DIR=${PREFIX}
NATIVE_VARS=			BOOT_DIST=${BOOTNAME}.${ARCH}-${OPSYS:tl}-${BOOTOSMAJ}.txz
NATIVE_VARS_OFF=		BOOT_DIST=
POLYML_BUILD_DEPENDS=		polyc:lang/polyml
#POLYML_CPPFLAGS=	-L/usr/local/lib -lpolyml -lpolymain
#POLYML_LDFLAGS=	-L/usr/local/lib -lpolyml -lpolymain
POLYML_ALL_TARGET=		polyml-mlton
POLYML_VARS=			BOOT_DIST= \
				MAKE_JOBS_UNSAFE= \
				yes
SMLNJ_BUILD_DEPENDS=		smlnj>=110.65:lang/smlnj
SMLNJ_MAKE_ENV=			SMLNJ_DEVEL=yes
SMLNJ_ALL_TARGET=		smlnj-mlton
SMLNJ_VARS=			BOOT_DIST= \
				MAKE_JOBS_UNSAFE=yes

.include <bsd.port.options.mk>

BOOT_WRKSRC=	${WRKSRC}/build
BOOT_WRKTMP=	${WRKDIR}/mlton-bootstrap

.if ${PORT_OPTIONS:MNATIVE} && ${OSREL:R} >= 13
BOOTOSMAJ=	13
.endif

BOOT_DIST_NEW=	${PKGNAME}${DISTVERSIONSUFFIX}.${ARCH}-${OPSYS:tl}-${OSREL:R}-${HOST}${BOOT_SUFX}

USE_GITHUB=	yes
GH_ACCOUNT=	MLton
GH_PROJECT=	mlton
GH_TAGNAME=	b2fca3d

BOOT_CMD=	--xz
BOOT_SUFX=	.txz

RAM_SLOP_32=	$$(${SYSCTL} "hw.physmem" | ${AWK} '{ values = values" "$$2 } END { print values; }' | ${AWK} '{ "freebsd-version -r" | getline ver; split(ver, xs, "\."); kernelOSMAJ = xs[1]; osj = ${BOOTOSMAJ}; physmem = $$1 / 1024 / 1024 / 1024; os = kernelOSMAJ; maxphysmem = physmem; if (physmem > 3.2) { maxphysmem = 3.2; }; ospcent = 0.70; if (osj < 13 && os != osj) { ospcent = 0.65; } else if (os >= 13) { if (physmem < 3.1) { ospcent = 0.83; } else { ospcent = 0.80; } }; targetmem = maxphysmem * ospcent; targetpcent = targetmem / physmem; print int((targetpcent + 0.005) * 100) / 100; }')

post-extract:
	@${MKDIR} ${BOOT_WRKSRC}
	@${REINPLACE_CMD} 's/CC := cc/CC := ${CC}/g' ${WRKSRC}/Makefile.config
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/doc/examples/ffi/Makefile
	@${REINPLACE_CMD} \
		's|-lpolymain -lpolyml|-L ${PREFIX}/lib -lpolymain -lpolyml|g' \
		${WRKSRC}/mlton/Makefile
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e "s/ram-slop 0\.7/ram-slop ${RAM_SLOP_32}/" \
		-e 's|COMPILE_XARGS :=|COMPILE_XARGS := -polyvariance false|' \
		${WRKSRC}/mlton/Makefile
	@${REINPLACE_CMD} -e "s/ram-slop 0\.7/ram-slop ${RAM_SLOP_32}/" \
		-e "s|^OLD_MLTON_RUNTIME_ARGS :=|OLD_MLTON_RUNTIME_ARGS := ram-slop ${RAM_SLOP_32}|" \
		-e 's|^OLD_MLTON_COMPILE_ARGS :=|OLD_MLTON_COMPILE_ARGS := -polyvariance false|' \
		${WRKSRC}/Makefile.config
.else
	@${REINPLACE_CMD} \
		-e 's|COMPILE_XARGS :=|COMPILE_XARGS := -polyvariance false|' \
		${WRKSRC}/mlton/Makefile
	@${REINPLACE_CMD} \
		-e 's|^OLD_MLTON_COMPILE_ARGS :=|OLD_MLTON_COMPILE_ARGS := -polyvariance false|' \
		${WRKSRC}/Makefile.config
.endif
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/mlnlffigen/gen-cppcmd
	@${REINPLACE_CMD} 's|"cc"|"${CC}"|g' ${WRKSRC}/bin/mlton-script
	@${FIND} ${WRKDIR} | ${GREP} '\.bak$$' | ${AWK} '{ system("${RM} "$$0); }'

post-extract-DOCS-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-extract-MLTON-on:
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_CMD} -C ${BOOT_WRKSRC}
	@${REINPLACE_CMD} \
		's|/usr/local/lib/mlton|${BOOT_WRKSRC}/lib/mlton|g' \
		${BOOT_WRKSRC}/bin/mlton
	@${REINPLACE_CMD} 's|$$gcc|$$CC|g' ${BOOT_WRKSRC}/bin/mlton

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MEXAMPLES}
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
.elif ${PORT_OPTIONS:MDOCS}
	${RM} -r ${STAGEDIR}${DOCSDIR}/examples
	${RMDIR} ${STAGEDIR}${EXAMPLESDIR}
.elif ${PORT_OPTIONS:MEXAMPLES}
#	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
#	${RM} -r ${STAGEDIR}${DOCSDIR}
	BROKEN+=	In port ${PORTNAME}, EXAMPLES requires DOCS
.endif
	@${FIND} ${WRKDIR} | ${GREP} '\.bak$$' | ${AWK} '{ system("${RM} "$$0); }'

makebootstrap: all
	@${ECHO_MSG} "====> Making new bootstrap image (${BOOT_DIST_NEW})"
#	@${FIND} ${WRKDIR} | ${GREP} '\.bak$$' | ${AWK} '{ system("${RM} "$$0); }'
	@${MKDIR} ${BOOT_WRKTMP}
	@cd ${STAGEDIR}${PREFIX} && ${CP} -pR lib bin ${BOOT_WRKTMP}/
	@${MKDIR} ${BOOT_WRKTMP}/doc && cd ${WRKSRC}/doc && \
		${CP} -pR license README.adoc CHANGELOG.adoc ${BOOT_WRKTMP}/doc/
	@cd ${WRKSRC} && ${CP} -pR LICENSE README.adoc CHANGELOG.adoc \
		${BOOT_WRKTMP}/
	@cd ${BOOT_WRKTMP} && \
		${TAR} cfp ${BOOT_WRKTMP}/${BOOT_DIST_NEW} ${BOOT_CMD} \
			lib bin doc LICENSE README.adoc CHANGELOG.adoc
	@${ECHO_MSG} "====> Installing new bootstrap image (${BOOT_DIST_NEW})"
	@${CP} -p ${BOOT_WRKTMP}/${BOOT_DIST_NEW} ${DISTDIR}/
	@${ECHO_MSG} "====> Backing up new bootstrap image (${BOOT_DIST_NEW})"
	@${MV} ${BOOT_WRKTMP}/${BOOT_DIST_NEW} ${MASTERDIR}/
##	@${RMDIR} ${BOOT_WRKTMP}

.include <bsd.port.mk>
