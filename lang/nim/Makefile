# Created by: Neal Nelson <ports@nicandneal.net>
# $FreeBSD$

PORTNAME=	nim
PORTVERSION=	1.0.6
CATEGORIES=	lang
MASTER_SITES=	https://nim-lang.org/download/

MAINTAINER=	ports@nicandneal.net
COMMENT=	Nim programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN_aarch64=		fails to compile: crt1.c: undefined reference to main
BROKEN_armv6=		fails to compile: crt1.c: undefined reference to main
BROKEN_armv7=		fails to compile: crt1.c: undefined reference to main
BROKEN_mips64=		fails to build: build.sh: clang: not found
BROKEN_sparc64=		fails to build: build.sh: clang: not found

TOOLS_DESC=	Build and install nimgrep and nimsuggest

OPTIONS_DEFINE=	DOCS TOOLS
OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=	yes
USES=		compiler tar:xz

.include <bsd.port.pre.mk>

TLIST=	nimgrep nimsuggest

.if ${ARCH} == "powerpc64"
.  if defined(PPC_ABI) && ${PPC_ABI} == ELFv1 
EXTRA_PATCHES=	${PATCHDIR}/elfv1-patch-build.sh
.  endif
.endif

post-patch:
.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
	@${REINPLACE_CMD} -e '/cc =/s/clang/gcc/' ${WRKSRC}/config/nim.cfg
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} CC="${CC}" LINKER="${CC}" \
		COMP_FLAGS="${CPPFLAGS} ${CFLAGS}" LINK_FLAGS="${LDFLAGS}" \
		${SH} build.sh
	cd ${WRKSRC} && bin/nim c --parallelBuild=${MAKE_JOBS_NUMBER} --nimcache=${WRKSRC}/nimcache koch
	cd ${WRKSRC} && ./koch boot --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release

do-build-TOOLS-on:
	cd ${WRKSRC} && ./koch tools --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release

do-install:
	cd ${WRKSRC} && ${SH} install.sh ${STAGEDIR}${PREFIX}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nim

do-install-TOOLS-on:
.for t in ${TLIST}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${t} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
