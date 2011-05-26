# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.9.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A documentation tool for Haskell

LICENSE=	BSD

USE_CABAL=	xhtml>=3000.2 ghc-paths
USE_ALEX=	true
USE_HAPPY=	true

EXECUTABLE=	haddock-${PORTVERSION}

PORTDATA=	*

SUB_FILES=	pkg-deinstall
SUB_LIST=	GHC_HADDOCK_CMD=${GHC_HADDOCK_CMD} HADDOCK=${PREFIX}/bin/haddock

CONFIGURE_ARGS=	--program-suffix=-${PORTVERSION}

post-install::
	@${LN} -sf ${PREFIX}/bin/${EXECUTABLE} ${PREFIX}/bin/haddock

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
