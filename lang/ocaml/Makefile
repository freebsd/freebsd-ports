# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated
PORTNAME=	ocaml
PORTVERSION=	4.01.0
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	${SFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	michipili@gmail.com
COMMENT=	The Objective Caml compiler and programming environment

LICENSE=		QPL10 LGPL20
LICENSE_COMB=		multi
LICENSE_NAME_QPL10=	Q Public License, Version 1.0
LICENSE_FILE_QPL10=	${WRKSRC}/LICENSE
LICENSE_PERMS_QPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake tar:bzip2
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
SSP_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	STAGEDIR="${STAGEDIR}"
CONFIGURE_ARGS=	-verbose -prefix "${PREFIX}" \
		-cc "${CC} ${CFLAGS}" \
		-as "${AS} ${ASFLAGS}" \
		-aspp "${CC} -c" \
		-partialld "${LD} -r"

OPTIONS_DEFINE= X11 TK THREADS DOCS EXAMPLES
OPTIONS_DEFAULT=X11 TK THREADS
TK_DESC=	LablTk library (requires X11 support)
CMP_LIB_DESC=	Install compiler libraries
PORTDOCS=	htmlman ${DOCSDISTNAME}-refman.ps.gz \
		${DOCSDISTNAME}-refman.pdf

MODOPT=		camlp4o camlp4r ocamlc ocamldep ocamldoc ocamllex ocamlopt
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]
DOCSDISTNAME=	${DISTNAME:C/([[:digit:]]+)\.([[:digit:]]+)\.([[:digit:]]+)/\1.\2/}

CONFLICTS=	metaocaml-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DOCSDISTNAME}-refman-html.tar.gz \
		${DOCSDISTNAME}-refman.ps.gz \
		${DOCSDISTNAME}-refman.pdf
EXTRACT_ONLY+=	${DOCSDISTNAME}-refman-html.tar.gz
PLIST_SUB+=	DOC=""
PORTDOCS=	htmlman ${DOCSDISTNAME}-refman.ps.gz ${DOCSDISTNAME}-refman.pdf
.else
PLIST_SUB+=	DOC="@comment "
.endif

.if ${ARCH} == armv6
CONFIGURE_ARGS+= -as "${AS} ${ASFLAGS} -mfpu=softvfp -meabi=5"
.else
CONFIGURE_ARGS+= -as "${AS} ${ASFLAGS}"
.endif

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
THR_CPP=	${PTHREAD_CFLAGS}
THR_LD=		${PTHREAD_LIBS}
.else
PLIST_SUB+=	THREADS="@comment "
THR_CPP=	#empty
THR_LD=		#empty
CONFIGURE_ARGS+=-no-pthread
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
USE_XORG=	x11
CONFLICTS+=	ocaml-nox11-[0-9]*
CONFIGURE_ARGS+=-x11include ${LOCALBASE}/include -x11lib ${LOCALBASE}/lib
.else
PLIST_SUB+=	X11="@comment "
SFX=		-nox11
CONFLICTS+=	ocaml-[0-9]*
CONFIGURE_ARGS+=-no-graph
.endif

.if ${PORT_OPTIONS:MTK}
. if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	examples_camltk examples_labltk
.endif
. if ! ${PORT_OPTIONS:MX11}
IGNORE=requires X11 support to build TK bindings
. endif
USES+=		tk:84+
PLIST_SUB+=	TK=""
CONFIGURE_ARGS+=	-tkdefs \
			"-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} ${THR_CPP}" \
			-tklibs "-L${LOCALBASE}/lib -ltk${TK_VER:S|.||} \
			-ltcl${TCL_VER:S|.||} ${THR_LD}"
.else
PLIST_SUB+=	TK="@comment "
CONFIGURE_ARGS+=-no-tk
.endif

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manfiles"

OCAML_ARCH= ${ARCH:S/x86_64/amd64/:S/powerpc/power/:S/armv6/arm/}

.if defined(NO_PROFILE) || ${OCAML_ARCH} == power || ${OPSYS} == DragonFly
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

.if ${OCAML_ARCH} == sparc64
BROKEN=	ocamlc.opt seg-faults on ${ARCH}, please try to fix
.endif

post-extract:
.if ${PORT_OPTIONS:MDOCS}
	@if ! (cd ${WRKDIR} && \
	  ${TAR} xf ${_DISTDIR}${DOCSDISTNAME}-refman-html.tar.gz \
	) \
	then \
	  exit 1; \
	fi;
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '\|MKLIB=|s|ar rc|${AR} rc|' \
		-e '\|RANLIB|s|ranlib|${RANLIB}|' \
		-e '\|bytecclinkopts=|s|""|"${LDFLAGS}"|' \
		-e "\|nativecclinkopts=|s|''|\"${LDFLAGS:C/-Wl,//}\"|" \
		-e '\|mksharedlib=|s|$$bytecc|& $$bytecclinkopts|' \
		-e 's|-lbfd -ldl|-lbfd $$dllib|' \
		${WRKSRC}/configure
# don't hardcode gcc for depend target
# be aware of staging
	@${REINPLACE_CMD} -E \
		-e 's|gcc|$$(CC)|' \
		-e '/^install/,/^$$/s@\$$\(((INSTALL_)?(BIN|LIB|STUBLIB|COMPLIB|MANO?|INSTALL|INSTALL_CUSTOM)DIR)\)@$$(STAGEDIR)$$(\1)@g' \
		`find ${WRKSRC} -name 'Makefile*'`
	@${REINPLACE_CMD} -E -e 's/^DIR=/DIR=$$(STAGEDIR)/' ${WRKSRC}/man/Makefile
.if ${PORT_OPTIONS:MTK}
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|' \
		${WRKSRC}/otherlibs/labltk/examples_labltk/hello.tcl
.endif

post-configure:
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|(BYTECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e 's|(NATIVECCCOMPOPTS[ \t]*=.*)|\1 ${CFLAGS} ${THR_CPP}|' \
		-e '/^PTHREAD_LINK/s,-pthread,${THR_LD},g' \
		${WRKSRC}/config/Makefile

# INSTALL* safeness (which preserves the correct permissions despite
# user's umask(1)
	@${FIND} ${WRKDIR} -type f -name Makefile -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's,\$$\(ARCH\),${OCAML_ARCH},g'	\
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \4,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,(${PATTERN}+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,'

check test: install
	@cd ${WRKSRC}/testsuite; ${RM} -f _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} report

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/ocamldoc/custom
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/ocaml/expunge
.if ${PORT_OPTIONS:MTK}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/otherlibs/labltk && \
		${COPYTREE_SHARE} examples_labltk ${STAGEDIR}${EXAMPLESDIR} \
		"! -name .ignore" && \
		${COPYTREE_SHARE} examples_camltk ${STAGEDIR}${EXAMPLESDIR} \
		"! -name .ignore")
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}${DOCSDISTNAME}-refman.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}${DOCSDISTNAME}-refman.pdf ${STAGEDIR}${DOCSDIR}
.endif

# Fix permissions for ld.conf
	@${CHMOD} 644 ${STAGEDIR}${PREFIX}/lib/ocaml/ld.conf

.include <bsd.port.post.mk>
