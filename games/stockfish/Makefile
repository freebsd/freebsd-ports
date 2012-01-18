# New ports collection makefile for:   stockfish
# Date created:		Apr 21 2011
# Whom:			Gautam Mani <execve@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stockfish
PORTVERSION=	2.2.1
CATEGORIES=	games
MASTER_SITES=	http://dl.dropbox.com/u/2116588/sf-archive/:src \
		http://www.execve.net/sf/:src \
		http://f.cl.ly/items/1y0Q3P2n0I2S0g0Y100E/:book \
		http://www.execve.net/sf/:book
DISTNAME=	stockfish-221-ja
DISTFILES=	stockfish-221-ja.zip:src \
		sf-211-book.zip:book

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

LICENSE=	GPLv3

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MYARCH=		${ARCH}
BOOKDIR=	sf-211-book
PORTDOCS=	Readme.txt polyglot.ini
PORTDATA=	Book.bin

PLIST_FILES=	bin/stockfish
PLIST_DIRSTRY=	share/data/${PORTNAME} \
		share/docs/${PORTNAME}

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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/polyglot.ini ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${BOOKDIR}/${PORTDATA} ${DATADIR}
.endif

.include <bsd.port.post.mk>
