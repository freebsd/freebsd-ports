# $FreeBSD$

PORTNAME=	ShellCheck
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	json mtl>=2.2.1 QuickCheck>=2.7.4 regex-tdfa

EXECUTABLE=	shellcheck

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
