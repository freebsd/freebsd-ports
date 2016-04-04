# $FreeBSD$

PORTNAME=	ShellCheck
PORTVERSION=	0.4.3
CATEGORIES=	devel haskell

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	json mtl>=2.2.1 parsec QuickCheck>=2.7.4 regex-tdfa

EXECUTABLE=	shellcheck

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
