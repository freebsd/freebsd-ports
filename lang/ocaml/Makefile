# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated

PORTNAME=	ocaml
PORTVERSION=	4.08.1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ GENTOO \
		http://caml.inria.fr/pub/distrib/${DISTNAME:R}/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:M*.tar.*}
PKGNAMESUFFIX=	${SFX}

MAINTAINER=	michipili@gmail.com
COMMENT=	Objective Caml compiler and programming environment
WWW=		https://ocaml.org/

LICENSE=		QPL10 LGPL20
LICENSE_COMB=		multi
LICENSE_NAME_QPL10=	Q Public License, Version 1.0
LICENSE_FILE_QPL10=	${WRKSRC}/LICENSE
LICENSE_PERMS_QPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_riscv64=		fails to build: hasgot.c:3:12: use of undeclared identifier 'secure_getenv'
BROKEN_mips64=	No ASM support
BROKEN_mips=	No ASM support

BUILD_DEPENDS=	as:devel/binutils
RUN_DEPENDS=	as:devel/binutils

USES=		cpe compiler:c11 gmake shebangfix tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	inria
GNU_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
PIE_UNSAFE=	yes
SSP_UNSAFE=	yes
LDFLAGS_armv6=	-Wl,-znotext
LDFLAGS_armv7=	-Wl,-znotext
LDFLAGS_i386=	-Wl,-znotext

SHEBANG_LANG=	awk
awk_OLD_CMD=	/bin/awk
awk_CMD=	/usr/bin/awk
SHEBANG_FILES=	tools/ocaml-instr-graph tools/ocaml-instr-report

CONFIGURE_ARGS= --prefix="${PREFIX}"
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" \
		ASPP="${CC} -c" \
		PARTIALLD="${LD} -r"
MAKE_ENV=	SYSTEM_ARCH="${ARCH:C/aarch64/arm64/:C/powerpc.*/power/}"

OPTIONS_DEFINE=	X11 THREADS DOCS EXAMPLES
OPTIONS_DEFAULT=X11 THREADS

OPTIONS_SUB=	yes

THREADS_CONFIGURE_ENABLE=	systhreads

X11_USES=	xorg
X11_CONFLICTS=	ocaml-nox11
X11_CONFLICTS_OFF=	ocaml
X11_USE=	XORG=x11
X11_CONFIGURE_WITH=	x
X11_CONFIGURE_ON=	--x-includes="${LOCALBASE}/include" \
			--x-libraries="${LOCALBASE}/lib"

CONFLICTS=	metaocaml

PORTDOCS=	htmlman ${DISTNAME:R}-refman.pdf

DOCS_DISTFILES=	${DISTNAME:R}-refman-html.tar.gz:docs \
		${DISTNAME:R}-refman.pdf:docs

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
PLIST_SUB+=	RAWSPACETIMELIB=" "
.else
PLIST_SUB+=	RAWSPACETIMELIB="@comment "
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ENV+=		AS="${AS} ${ASFLAGS} -meabi=5" \
			CC="${CC}"
.elif ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
CONFIGURE_ENV+=		CC="${CC} -fuse-ld=bfd"
.else
CONFIGURE_ENV+=		AS="${AS} ${ASFLAGS}" \
			CC="${CC}"
.endif

.if defined(NO_PROFILE) || ${ARCH:Mpowerpc} || ${ARCH:Mamd64}
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '\|MKLIB=|s|ar rc|${AR} rc|' \
		-e '\|RANLIB|s|ranlib|${RANLIB}|' \
		-e '\|^ldflags=|s|""|"${LDFLAGS}"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,$$(ARCH),$$(SYSTEM_ARCH),' \
		${WRKSRC}/Makefile ${WRKSRC}/Makefile.tools \
		${WRKSRC}/runtime/Makefile \
		${WRKSRC}/ocamltest/Makefile \
		${WRKSRC}/otherlibs/systhreads/Makefile

check-test: do-install
	@cd ${WRKSRC}/testsuite; ${RM} _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} report

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}${DISTNAME:R}-refman.pdf ${STAGEDIR}${DOCSDIR}
.endif
# Spacetime profiling is only available for native code on 64-bit targets
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc
	@${REINPLACE_CMD} -e '/raw_spacetime_lib/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
