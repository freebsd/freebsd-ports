# New ports collection makefile for:	chameleon
# Date created:				26 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chameleon
PORTVERSION=	03.11
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.comp.nus.edu.sg/~sulzmann/chameleon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell-style language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		happy:${PORTSDIR}/devel/hs-happy

ALL_TARGET=	just-boo

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chameleon ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/interface/Prelude.ch  ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
