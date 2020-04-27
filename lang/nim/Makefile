# Created by: Neal Nelson <ports@nicandneal.net>
# $FreeBSD$

PORTNAME=	nim
PORTVERSION=	1.2.0
CATEGORIES=	lang
MASTER_SITES=	https://nim-lang.org/download/

MAINTAINER=	ports@nicandneal.net
COMMENT=	Nim programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN_mips64=		fails to build: build.sh: clang: not found
BROKEN_sparc64=		fails to build: build.sh: clang: not found

USES=		compiler tar:xz

TOOLS_DESC=	Build and install nim tools

OPTIONS_DEFINE=	DOCS TOOLS
OPTIONS_DEFAULT=	DOCS TOOLS

OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

TLIST=	nimfind nimgrep nimpretty nimsuggest testament

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
	cd ${WRKSRC} && bin/nim c --parallelBuild=${MAKE_JOBS_NUMBER} \
		--nimcache=${WRKDIR}/nimcache koch
	cd ${WRKSRC} && ./koch boot --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release --nimcache=${WRKDIR}/nimcache

do-build-TOOLS-on:
	cd ${WRKSRC} && ./koch toolsNoNimble --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release --nimcache=${WRKDIR}/nimcache

do-install:
	cd ${WRKSRC} && ${SH} install.sh ${STAGEDIR}${PREFIX}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nim

do-install-TOOLS-on:
.for t in ${TLIST}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${t} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
