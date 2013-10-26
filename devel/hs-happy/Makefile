# Created by: Simon Marlow <simonmar@microsoft.com>
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.18.10
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Happy is a parser generator for Haskell

LICENSE=	BSD

USE_CABAL=	mtl>=1.0

XMLDOCS=	doc/happy:html
USE_AUTOTOOLS=	autoconf:env

STANDALONE=	yes
EXECUTABLE=	happy

INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
