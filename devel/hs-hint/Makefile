# New ports collection makefile for: hs-hint
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hint
PORTVERSION=	0.3.2.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Runtime Haskell interpreter (GHC API wrapper)

USE_HACKAGE=	ghc-mtl>=1.0.1.0 ghc-paths MonadCatchIO-mtl>=0.2 utf8-string

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
	
PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DATADIR} \
			  && ${INSTALL_DATA} ${WRKSRC}/Changes ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
