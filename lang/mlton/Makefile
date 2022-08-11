# Previously maintained by Jesper Louis Andersen
# (jesper.louis.andersen@gmail.com) and Geoffrey Mainland
# (mainland@apeiron.net)
#
# Because MLton is written in SML, it needs an SML compiler to build.
# It is easiest to use another (earlier) binary version of MLton as
# the SML compiler.  So, this Makefile fetches and installs an
# already-built version of MLton, BOOT_DIST, to use for bootstrapping.
PORTNAME=	mlton
PORTVERSION=	20210816
CATEGORIES=	lang
MASTER_SITES+=	https://github.com/beyert/mlton-freebsd_bootstrap/raw/c7371c1/:bootstrap
DISTFILES+= ${BOOTNAME}.i386-${OPSYS:tl}-13.txz:bootstrap \
	${BOOTNAME}.amd64-${OPSYS:tl}-13.txz:bootstrap \
	${BOOTNAME}.i386-${OPSYS:tl}-12.txz:bootstrap \
	${BOOTNAME}.amd64-${OPSYS:tl}-12.txz:bootstrap \
	${BOOTNAME}.i386-${OPSYS:tl}-11.txz:bootstrap \
	${BOOTNAME}.amd64-${OPSYS:tl}-11.txz:bootstrap

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Optimizing Standard ML compiler

LICENSE=	HPND
LICENSE_GROUPS=	COPYFREE OSI
LICENSE_NAME=	Historical Permission Notice and Disclaimer
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	bash:shells/bash

USES=	compiler:c11 gmake

BOOTNAME=	${BOOTNAMEPREFIX}${PORTNAME}${BOOTNAMESUFFIX}-${BOOTVERSIONPREFIX}${BOOTVERSION}${BOOTVERSIONSUFFIX}
BOOTVERSIONSUFFIX=
BOOTVERSION=	${PORTVERSION}
BOOTOSMAJ=	${OSREL:R}

OPTIONS_DEFINE=	DOCS EXAMPLES

OPTIONS_SINGLE=	TARGET BOOTSTRAP
OPTIONS_SINGLE_TARGET=	NATIVE MINGW32
OPTIONS_SINGLE_BOOTSTRAP=	MLTON SMLNJ POLYML WINE

OPTIONS_DEFAULT=	NATIVE MLTON

MLTON_DESC=		Bootstrap with MLton (ideal if supported)
SMLNJ_DESC=		Bootstrap with SML/NJ (can take many hours)
POLYML_DESC=	Bootstrap with PolyML
WINE_DESC=		Bootstrap MINGW32 with wine

NATIVE_DESC=	Use default target for given architecture
MINGW32_DESC=	Add mingw32 Windows target (requires wine)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMINGW32}
BROKEN+=	not yet implemented MINGW32 option in modern versions of ${PORTNAME}
.endif

BOOT_WRKSRC=	${WRKSRC}/build
BOOT_WRKTMP=	${WRKDIR}/mlton-bootstrap

.if ! ${PORT_OPTIONS:MMLTON}
MAKE_ARGS=	DESTDIR='' MLTON_VERSION=${PORTVERSION} \
	PATH=${WRKSRC}/build/bin:${WRKDIR}/bin:${PATH} \
	PREFIX=${PREFIX} \
	WITH_GMP_DIR=${PREFIX}
.else
MAKE_ARGS=	DESTDIR='' MLTON_VERSION=${PORTVERSION} \
	PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
	PREFIX=${PREFIX} \
	SML_LIB=${BOOT_WRKSRC}/lib/sml WITH_GMP_DIR=${PREFIX} \
	PREFIX=${PREFIX} LIB=${BOOT_WRKSRC}/lib \
	TDOC=${STAGEDIR}${DOCSDIR} \
	TEXM=${STAGEDIR}${EXAMPLESDIR}
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	htmldoc:textproc/htmldoc
MAKE_ARGS+=	MLTON_BINARY_RELEASE_WITH_DOCS=true
#USE_TEX=	latex:build
USE_TEX=	latex:formats
INSTALL_TARGET=	install-docs install
ALL_TARGET=	install-docs all
.else
MAKE_ARGS+=	MLTON_BINARY_RELEASE_WITH_DOCS=false
INSTALL_TARGET=	install
ALL_TARGET=	all
.endif

.if ${PORT_OPTIONS:MSMLNJ}
BUILD_DEPENDS+=	smlnj>=110.65:lang/smlnj
BOOT_DIST=
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	SMLNJ_DEVEL=yes
.if ! ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	smlnj-mlton all
.else
ALL_TARGET=	smlnj-mlton install-docs all
.endif
.elif ${PORT_OPTIONS:MPOLYML}
BUILD_DEPENDS+=	polyc:lang/polyml
BOOT_DIST=
MAKE_JOBS_UNSAFE=	yes
#CPPFLAGS+=	-L/usr/local/lib -lpolyml -lpolymain
#LDFLAGS+=	-L/usr/local/lib -lpolyml -lpolymain
.if ! ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	polyml-mlton all
.else
ALL_TARGET=	polyml-mlton install-docs all
.endif
.elif ${PORT_OPTIONS:MNATIVE}
BOOT_DIST=	${BOOTNAME}.${ARCH}-${OPSYS:tl}-${BOOTOSMAJ}.txz
.else
BOOT_DIST=
.endif

BOOT_DIST_NEW=	${PKGNAME}${DISTVERSIONSUFFIX}.${ARCH}-${OPSYS:tl}-${OSREL:R}-${HOST}${BOOT_SUFX}

.if ${PORT_OPTIONS:MMINGW32} && ${PORT_OPTIONS:MWINE}
BUILD_DEPENDS+=	wine:emulators/wine \
		mingw32-gcc:devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:math/mingw32-libgmp
RUN_DEPENDS+=	mingw32-gcc:devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:math/mingw32-libgmp
SSP_CFLAGS?=	-fstack-protector	# XXX -strong isn't supported by GCC < 4.9

PLIST_SUB+=	MINGW32CROSS=""
.else
PLIST_SUB+=	MINGW32CROSS="@comment "
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	MLton
GH_PROJECT=	mlton
GH_TAGNAME=	b2fca3d

BOOT_CMD=	--xz
BOOT_SUFX=	.txz

post-extract:
	@${MKDIR} ${BOOT_WRKSRC}
.if ${PORT_OPTIONS:MMLTON}
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_CMD} -C ${BOOT_WRKSRC}
	@${REINPLACE_CMD} \
		's|/usr/local/lib/mlton|${BOOT_WRKSRC}/lib/mlton|g' \
		${BOOT_WRKSRC}/bin/mlton
	@${REINPLACE_CMD} 's|$$gcc|$$CC|g' ${BOOT_WRKSRC}/bin/mlton
.endif
	@${REINPLACE_CMD} 's/CC := cc/CC := ${CC}/g' ${WRKSRC}/Makefile.config
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/doc/examples/ffi/Makefile
	@${REINPLACE_CMD} \
		's|-lpolymain -lpolyml|-L ${PREFIX}/lib -lpolymain -lpolyml|g' \
		${WRKSRC}/mlton/Makefile
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${ARCH} == "i386"
.if ${OSREL:R} == 13
	@${REINPLACE_CMD} -e 's/ram-slop 0\.7/ram-slop 0.8/' \
		-e 's|COMPILE_XARGS :=|COMPILE_XARGS := -polyvariance false|' \
		${WRKSRC}/mlton/Makefile
.else
	@${REINPLACE_CMD} -e 's/ram-slop 0\.7/ram-slop 0.7/' \
		-e 's|COMPILE_XARGS :=|COMPILE_XARGS := -polyvariance false|' \
		${WRKSRC}/mlton/Makefile
.endif
	@${REINPLACE_CMD} -e 's/ram-slop 0\.7/ram-slop 0.8/' \
		-e 's|^OLD_MLTON_RUNTIME_ARGS :=|OLD_MLTON_RUNTIME_ARGS := ram-slop 0.8|' \
		-e 's|^OLD_MLTON_COMPILE_ARGS :=|OLD_MLTON_COMPILE_ARGS := -polyvariance false|' \
		${WRKSRC}/Makefile.config
.endif
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/mlnlffigen/gen-cppcmd
	@${REINPLACE_CMD} 's|"cc"|"${CC}"|g' ${WRKSRC}/bin/mlton-script
	@${FIND} ${WRKDIR} | ${GREP} '\.bak$$' | ${AWK} '{ system("${RM} "$$0); }'

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

makebootstrap:	all
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

post-build-MINGW32-on:
	@${ECHO} Adding mingw32 target...
	${WRKSRC}/bin/add-local-cross mingw32 x86 mingw

.include <bsd.port.mk>
