# Created by: Gautam Mani <execve@gmail.com>
# $FreeBSD$

PORTNAME=	stockfish
PORTVERSION=	5
CATEGORIES=	games
MASTER_SITES=	http://stockfish.s3.amazonaws.com/:src \
		http://cl.ly/3x333m0G173F/download/:book \
		http://www.execve.net/sf/:book
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.zip:src \
		${PORTNAME}-231-book.zip:book

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

LICENSE=	GPLv3

NOT_FOR_ARCHS=	sparc64
BROKEN_aarch64=	Fails to build: cannot detect architecture
BROKEN_mips64=	Fails to build: cannot detect architecture

USES=		compiler gmake zip

WRKSRC=		${WRKDIR}/${DISTNAME}/src
BOOKDIR=	.
MYARCH=		${ARCH}
MYCC=		${COMPILER_TYPE}
TGTBLD=		build

PLIST_FILES=	bin/stockfish
PORTDATA=	Book.bin
PORTDOCS=	Readme.md polyglot.ini

OPTIONS_DEFINE=	DOCS POPCNT PROFILE

POPCNT_DESC=	Use the POPCNT instruction

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE}
TGTBLD=		profile-build
.endif

.if ${PORT_OPTIONS:MPOPCNT} && ${ARCH} != amd64
BROKEN=		POPCNT compiles only on amd64
.endif

# workaround the ARCH usage in the stockfish Makefile
.if ${ARCH} == "i386"
MYARCH=		x86-32
.elif ${ARCH} == "amd64"
.  if ${PORT_OPTIONS:MPOPCNT}
MYARCH=		x86-64-modern
.  else
MYARCH=		x86-64
.  endif
.elif ${ARCH} == powerpc
MYARCH=		ppc-32
.elif ${ARCH} == powerpc64
MYARCH=		ppc-64
.endif

ALL_TARGET=	${TGTBLD} ARCH=${MYARCH} COMP=${MYCC}

post-patch:
	@${REINPLACE_CMD} -e "s/^PREFIX =/PREFIX ?=/" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${BOOKDIR}/${PORTDATA} ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Readme.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/polyglot.ini ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
