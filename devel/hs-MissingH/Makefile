# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	MissingH
PORTVERSION=	1.4.0.1
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Large utility library

LICENSE=	BSD3CLAUSE

BROKEN=		Doesn't compile with newest GHC

USE_CABAL=	hslogger HUnit mtl network old-time random regex-compat

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
