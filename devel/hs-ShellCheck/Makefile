# $FreeBSD$

PORTNAME=	ShellCheck
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	devel haskell

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	aeson QuickCheck>=2.7.4 regex-tdfa
USE_GITHUB=	yes
GH_ACCOUNT=	koalaman
GH_PROJECT=	${PORTNAME:tl}

EXECUTABLE=	shellcheck
IGNORE_DOCS=	yes
IGNORE_DYNAMIC=	yes
IGNORE_PROFILE=	yes
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
