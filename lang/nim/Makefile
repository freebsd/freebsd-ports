# Created by: Neal Nelson <ports@nicandneal.net>
# $FreeBSD$

PORTNAME=	nim
PORTVERSION=	0.15.0
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/

MAINTAINER=	ports@nicandneal.net
COMMENT=	Nim programming language

LICENSE=	MIT

BROKEN_aarch64=		Does not compile: crt1.c: undefined reference to main
BROKEN_mips64=		Does not build: build.sh: clang: not found
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: build.sh: clang: not found

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes
USES=		compiler tar:xz

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e '/cc =/s/gcc/clang/' ${WRKSRC}/config/nim.cfg
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} CC="${CC}" LINKER="${CC}" \
		COMP_FLAGS="${CPPFLAGS} ${CFLAGS}" LINK_FLAGS="${LDFLAGS}" \
		${SH} build.sh
	cd ${WRKSRC} && bin/nim c --parallelBuild=${MAKE_JOBS_NUMBER} koch
	cd ${WRKSRC} && ./koch boot --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release

do-install:
	cd ${WRKSRC} && ${SH} install.sh ${STAGEDIR}${PREFIX}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nim

.include <bsd.port.post.mk>
