# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$
# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated

PORTNAME=	ocaml
PORTVERSION=	4.05.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ GENTOO \
		http://caml.inria.fr/pub/distrib/${DISTNAME:R}/:docs
PKGNAMESUFFIX=	${SFX}

MAINTAINER=	michipili@gmail.com
COMMENT=	Objective Caml compiler and programming environment

LICENSE=		QPL10 LGPL20
LICENSE_COMB=		multi
LICENSE_NAME_QPL10=	Q Public License, Version 1.0
LICENSE_FILE_QPL10=	${WRKSRC}/LICENSE
LICENSE_PERMS_QPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		Does not build: sh: as: not found
BROKEN_sparc64=	No rule to make target 'none.o', needed by 'libasmrun.a'
BROKEN_mips64=	No ASM support
BROKEN_mips=	No ASM support

USES=		cpe compiler:c11 gmake tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	inria
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
SSP_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes
LDFLAGS_armv7=	-Wl,-znotext
LDFLAGS_i386=	-Wl,-znotext

CONFIGURE_ARGS=	-verbose -prefix "${PREFIX}" \
		-cc "${CC}" \
		-aspp "${CC} -c" \
		-partialld "${LD} -r"

OPTIONS_DEFINE=	X11 THREADS DOCS EXAMPLES
OPTIONS_DEFAULT=X11 THREADS
CMP_LIB_DESC=	Install compiler libraries

MODOPT=		camlp4o camlp4r ocamlc ocamldep ocamldoc ocamllex ocamlopt
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]
DOCSDISTNAME=	${DISTNAME:C/([[:digit:]]+)\.([[:digit:]]+)\.([[:digit:]]+)/\1.\2/}

CONFLICTS=	metaocaml-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES:=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCSDISTNAME}-refman-html.tar.gz:docs \
		${DOCSDISTNAME}-refman.ps.gz:docs \
		${DOCSDISTNAME}-refman.pdf:docs
EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCSDISTNAME}-refman-html.tar.gz
PLIST_SUB+=	DOC=""
PORTDOCS=	htmlman ${DOCSDISTNAME}-refman.ps.gz ${DOCSDISTNAME}-refman.pdf
.else
PLIST_SUB+=	DOC="@comment "
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ARGS+=	-as "${AS} ${ASFLAGS} -meabi=5"
.else
CONFIGURE_ARGS+=	-as "${AS} ${ASFLAGS}"
.endif

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
THR_LD=		-lpthread
.else
PLIST_SUB+=	THREADS="@comment "
THR_LD=		#empty
CONFIGURE_ARGS+=-no-pthread
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
USES+=		xorg
USE_XORG=	x11
CONFLICTS+=	ocaml-nox11-[0-9]*
CONFIGURE_ARGS+=-x11include ${LOCALBASE}/include -x11lib ${LOCALBASE}/lib
.else
PLIST_SUB+=	X11="@comment "
SFX=		-nox11
CONFLICTS+=	ocaml-[0-9]*
CONFIGURE_ARGS+=-no-graph
.endif

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || ${ARCH:Mpowerpc} || ${ARCH:Mamd64}
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
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
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,$$(ARCH),$$(SYSTEM_ARCH),' \
		${WRKSRC}/Makefile ${WRKSRC}/Makefile.tools \
		${WRKSRC}/asmrun/Makefile \
		${WRKSRC}/otherlibs/systhreads/Makefile \
		${WRKSRC}/testsuite/makefiles/Makefile.common \
		${WRKSRC}/testsuite/tests/asmcomp/Makefile

post-configure:
	@${REINPLACE_CMD} -E \
		-e '/^PTHREAD_LINK/s,-pthread,${THR_LD},g' \
		${WRKSRC}/config/Makefile
# INSTALL* safeness (which preserves the correct permissions despite
# user's umask(1)
	@${FIND} ${WRKDIR} -type f -name Makefile -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \4,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,(${PATTERN}+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,'

check-test: do-install
	@cd ${WRKSRC}/testsuite; ${RM} _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} report

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}${DOCSDISTNAME}-refman.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}${DOCSDISTNAME}-refman.pdf ${STAGEDIR}${DOCSDIR}
.endif
# Spacetime profiling is only available for native code on 64-bit targets
.if ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc
	@${REINPLACE_CMD} -e '/raw_spacetime_lib/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
