# $FreeBSD$

PORTNAME=	ShellCheck
PORTVERSION=	0.3.5
CATEGORIES=	devel haskell

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Shell script analysis tool

LICENSE=	AGPLv3

USE_CABAL=	json>=0.7 parsec QuickCheck>=2.6 regex-posix>=0.95.2 \
		regex-compat>=0.95.1 tf-random>=0.5

EXECUTABLE=	shellcheck

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
