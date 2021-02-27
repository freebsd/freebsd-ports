# Created by: Simon Marlow <simonmar@microsoft.com>
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.20.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parser generator for Haskell

LICENSE=	BSD3CLAUSE

USES=		cabal

PORTEXAMPLES=	*.ly README glr/* igloo/*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} $$(find ${WRKSRC} -name 'HappyTemplate*') ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
