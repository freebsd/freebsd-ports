# New ports collection makefile for:	chameleon
# Date created:				26 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chameleon
PORTVERSION=	03.08
CATEGORIES=	lang
MASTER_SITES=	http://www.comp.nus.edu.sg/~sulzmann/chameleon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A Haskell-style language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		happy:${PORTSDIR}/devel/hs-happy

ALL_TARGET=	just-boo

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chameleon ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/samples -type f -exec \
		${INSTALL_DATA} {} ${EXAMPLESDIR} \;

.include <bsd.port.mk>
