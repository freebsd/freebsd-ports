# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	chicken
PORTVERSION=	4.8.0.5
CATEGORIES=	lang scheme
MASTER_SITES=	http://code.call-cc.org/releases/4.8.0/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme-to-C compiler

USES=	gmake
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_ARGS+=	PLATFORM=bsd PREFIX=${PREFIX} \
		TOPMANDIR=${PREFIX}/man ARCH=${NEW_ARCH} \
		C_COMPILER="${CC}" \
		CXX_COMPILER="${CXX}" \
		LIBRARIAN="${AR}" \
		DOCDIR="${DOCSDIR}" \
		C_COMPILER_OPTIMIZATION_OPTIONS="${CFLAGS}"

NEW_ARCH=	${ARCH:S/i386/x86/:S/amd64/x86-64/}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ${ARCH} != "i386" && ${ARCH} != "sparc64"
MAKE_ARGS+=	HACKED_APPLY=
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

# This only works *after* chicken is installed.
regression-test: build
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
