# New ports collection makefile for:   stockfish
# Date created:		Apr 21 2011
# Whom:			Gautam Mani <execve@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stockfish
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://f.cl.ly/items/1W3R1i3c3Y2n0m133q15/:src \
		http://www.execve.net/sf/:src \
		http://f.cl.ly/items/1y0Q3P2n0I2S0g0Y100E/:book \
		http://www.execve.net/sf/:book
DISTNAME=	sf-211-linux-eng
DISTFILES=	sf-211-linux-eng.zip:src \
		sf-211-book.zip:book

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

LICENSE=	GPLv3

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MYARCH=		${ARCH}
BOOKDIR=	sf-211-book

ALL_TARGET=	build ARCH=${MYARCH}

OPTIONS=	POPCNT_PROFILE_BUILD       "Make a Profile build (POPCNT enabled)" Off \
		PROFILE_BUILD "Make a Profile build" Off

TGTBLD=		build

.include <bsd.port.options.mk>

.if defined(WITH_PROFILE_BUILD)
TGTBLD=		profile-build
.endif

.if defined(WITH_POPCNT_PROFILE_BUILD)
.if ${ARCH} != "amd64"
BROKEN=		WITH_POPCNT_PROFILE_BUILD compiles only on amd64
.endif
TGTBLD=		popcnt-profile-build
.endif

.include <bsd.port.pre.mk>

# workaround the ARCH usage in the stockfish Makefile
.if ${MYARCH} == "i386"
ALL_TARGET=	${TGTBLD} ARCH=x86-32
.elif ${MYARCH} == "amd64"
ALL_TARGET=	${TGTBLD} ARCH=x86-64
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${PREFIX}/bin/stockfish
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/polyglot.ini ${DOCSDIR}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${BOOKDIR}/Book.bin ${DATADIR}

.include <bsd.port.post.mk>
