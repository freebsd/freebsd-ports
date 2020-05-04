# $FreeBSD$

PORTNAME=	profiteur
PORTVERSION=	0.4.5.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	aeson-1.4.6.0 \
		attoparsec-0.13.2.3_1 \
		base-compat-0.11.1 \
		base-orphans-0.8.2 \
		dlist-0.8.0.7 \
		ghc-prof-1.4.1.6 \
		hashable-1.3.0.0 \
		integer-logarithms-1.0.3_2 \
		js-jquery-3.3.1 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		scientific-0.3.6.2 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.3 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2

profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
