# New ports collection makefile for:	chameleon
# Date created:				26 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chameleon
DISTVERSION=	05-07
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.comp.nus.edu.sg/~sulzmann/chameleon/download/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell-style language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		happy:${PORTSDIR}/devel/hs-happy

BROKEN=		Does not build

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src
MAKE_ARGS=	GHC=ghc INSTALL_PATH='\"${DATADIR}/\"'

post-patch:
	${REINPLACE_CMD} 's|gcc -O3|${CC} ${CFLAGS}|' ${WRKSRC}/Solvers/Makefile
	@${RMDIR} ${WRKSRC}/../lib/Haskell98

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chameleon ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -pr ${WRKSRC}/../lib ${DATADIR}
	@${MKDIR} ${DATADIR}/src/Backends/Scheme/Prologue
	${CP} -pr ${WRKSRC}/Backends/Scheme/Prologue/* ${DATADIR}/src/Backends/Scheme/Prologue

.include <bsd.port.mk>
