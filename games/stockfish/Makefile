# New ports collection makefile for:   stockfish
# Date created:		Apr 21 2011
# Whom:			Gautam Mani <execve@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stockfish
PORTVERSION=	2.1.1
CATEGORIES=	games
MASTER_SITES=	http://f.cl.ly/items/3E1y252w3q0R3C050k01/
DISTNAME=	stockfish-211-ja

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MYARCH=		${ARCH}

ALL_TARGET=	build ARCH=${MYARCH}

.include <bsd.port.pre.mk>

# workaround the ARCH usage in the stockfish Makefile
.if ${MYARCH} == "i386"
MYARCH=		x86-32
ALL_TARGET=	build ARCH=${MYARCH}
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${PREFIX}/bin/stockfish
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/polyglot.ini ${DOCSDIR}

.include <bsd.port.post.mk>
