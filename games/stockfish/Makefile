# Created by: Gautam Mani <execve@gmail.com>
# $FreeBSD$

PORTNAME=	stockfish
PORTVERSION=	3
CATEGORIES=	games
MASTER_SITES=	http://cl.ly/2n1O3h2d3u2W/download/:src \
		http://www.execve.net/sf/:src \
		http://cl.ly/3x333m0G173F/download/:book \
		http://www.execve.net/sf/:book
DISTNAME=	stockfish-${PORTVERSION:S/.//g}-linux
DISTFILES=	stockfish-${PORTVERSION:S/.//g}-linux.zip:src \
		stockfish-231-book.zip:book

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

LICENSE=	GPLv3

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MYARCH=		${ARCH}
BOOKDIR=	.
PORTDOCS=	Readme.txt polyglot.ini
PORTDATA=	Book.bin
FETCH_ARGS=	-Fpr

PLIST_FILES=	bin/stockfish

TGTBLD=		build
MYCC=		gcc

.if ${CC} == "clang" || ${CXX} == "clang++"
MYCC=	clang
.endif

OPTIONS_DEFINE=	DOCS POPCNT_ENABLED PROFILE_BUILD
POPCNT_ENABLED_DESC=	Use the POPCNT instruction
PROFILE_BUILD_DESC=	Make a Profile build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE_BUILD}
TGTBLD=		profile-build
.endif

.if ${PORT_OPTIONS:MPOPCNT_ENABLED}
.if ${ARCH} != "amd64"
BROKEN=		POPCNT_ENABLED compiles only on amd64
.endif
.endif

.include <bsd.port.pre.mk>

# workaround the ARCH usage in the stockfish Makefile
.if ${ARCH} == "i386"
MYARCH=		x86-32
.elif ${ARCH} == "amd64"
.if ${PORT_OPTIONS:MPOPCNT_ENABLED}
MYARCH=		x86-64-modern
.else
MYARCH=		x86-64
.endif
.endif
ALL_TARGET=	${TGTBLD} ARCH=${MYARCH} COMP=${MYCC}

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${PREFIX}/bin/stockfish

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/polyglot.ini ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${BOOKDIR}/${PORTDATA} ${DATADIR}
.endif

.include <bsd.port.post.mk>
