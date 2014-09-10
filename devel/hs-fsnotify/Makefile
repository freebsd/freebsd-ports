# $FreeBSD$

PORTNAME=	fsnotify
PORTVERSION=	0.1.0.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform library for file system notifications

LICENSE=	BSD3CLAUSE

USE_CABAL=	async>=2.0.1 hinotify>=0.3.7 system-fileio>=0.3.8 \
		system-filepath>=0.4.6 text>=0.11.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
