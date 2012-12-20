# $FreeBSD$

PORTNAME=	fsnotify
PORTVERSION=	0.0.4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform library for file system notifications

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	hinotify>=0.3.5 system-fileio>=0.3.8 system-filepath>=0.4.6 \
		text>=0.11.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
