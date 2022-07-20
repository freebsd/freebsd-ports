# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated

PORTNAME=	ocaml
PORTVERSION=	4.07.1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ GENTOO \
		http://caml.inria.fr/pub/distrib/${DISTNAME:R}/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:M*.tar.*}
PKGNAMESUFFIX=	${SFX}

MAINTAINER=	michipili@gmail.com
COMMENT=	Objective Caml compiler and programming environment

LICENSE=		QPL10 LGPL20
LICENSE_COMB=		multi
LICENSE_NAME_QPL10=	Q Public License, Version 1.0
LICENSE_FILE_QPL10=	${WRKSRC}/LICENSE
LICENSE_PERMS_QPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_riscv64=		fails to build: hasgot.c:3:12: use of undeclared identifier 'secure_getenv'
BROKEN_sparc64=	No rule to make target 'none.o', needed by 'libasmrun.a'
BROKEN_mips64=	No ASM support
BROKEN_mips=	No ASM support

BUILD_DEPENDS=	as:devel/binutils
RUN_DEPENDS=	as:devel/binutils

USES=		cpe compiler:c11 gmake shebangfix tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	inria
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
SSP_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes
LDFLAGS_armv6=	-Wl,-znotext
LDFLAGS_armv7=	-Wl,-znotext
LDFLAGS_i386=	-Wl,-znotext

SHEBANG_LANG=	awk
awk_OLD_CMD=	/bin/awk
awk_CMD=	/usr/bin/awk
SHEBANG_FILES=	tools/ocaml-instr-graph tools/ocaml-instr-report

CONFIGURE_ARGS=	-verbose -prefix "${PREFIX}" \
		-cc "${CC}" \
		-aspp "${CC} -c" \
		-partialld "${LD} -r"

OPTIONS_DEFINE=	X11 THREADS DOCS EXAMPLES
OPTIONS_DEFAULT=X11 THREADS

CONFLICTS=	metaocaml

PORTDOCS=	htmlman ${DISTNAME:R}-refman.ps.gz ${DISTNAME:R}-refman.pdf

DOCS_DISTFILES=	${DISTNAME:R}-refman-html.tar.gz:docs \
		${DISTNAME:R}-refman.ps.gz:docs \
		${DISTNAME:R}-refman.pdf:docs

.include <bsd.port.options.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ARGS+=	-as "${AS} ${ASFLAGS} -meabi=5"
.elif ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LLD_UNSAFE=		yes
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
CONFLICTS+=	ocaml-nox11
CONFIGURE_ARGS+=-x11include ${LOCALBASE}/include -x11lib ${LOCALBASE}/lib
.else
PLIST_SUB+=	X11="@comment "
SFX=		-nox11
CONFLICTS+=	ocaml
CONFIGURE_ARGS+=-no-graph
.endif

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || ${ARCH:Mpowerpc} || ${ARCH:Mamd64}
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-asmcomp_power_arch.ml
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '\|MKLIB=|s|ar rc|${AR} rc|' \
		-e '\|RANLIB|s|ranlib|${RANLIB}|' \
		-e '\|^ldflags=|s|""|"${LDFLAGS}"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,$$(ARCH),$$(SYSTEM_ARCH),' \
		${WRKSRC}/Makefile ${WRKSRC}/Makefile.tools \
		${WRKSRC}/asmrun/Makefile \
		${WRKSRC}/ocamltest/Makefile \
		${WRKSRC}/otherlibs/systhreads/Makefile \
		${WRKSRC}/testsuite/tests/asmgen/Makefile

post-configure:
	@${REINPLACE_CMD} -E \
		-e '/^PTHREAD_LINK/s,-pthread,${THR_LD},g' \
		${WRKSRC}/config/Makefile

check-test: do-install
	@cd ${WRKSRC}/testsuite; ${RM} _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} report

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}${DISTNAME:R}-refman.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}${DISTNAME:R}-refman.pdf ${STAGEDIR}${DOCSDIR}
.endif
# Spacetime profiling is only available for native code on 64-bit targets
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc
	@${REINPLACE_CMD} -e '/raw_spacetime_lib/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
