# Created by: Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tool for generating lexical analysers in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	QuickCheck>=2

XMLDOCS=	doc/alex:html
XMLDOCS_CONF=	yes

STANDALONE=	yes
EXECUTABLE=	alex

INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
