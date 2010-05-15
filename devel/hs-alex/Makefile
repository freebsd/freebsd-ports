# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.3.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

XMLDOCS=	doc/alex:html
USE_AUTOTOOLS=	autoconf:262:env

STANDALONE=	yes
EXECUTABLE=	alex

PORTDATA=		*
PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
