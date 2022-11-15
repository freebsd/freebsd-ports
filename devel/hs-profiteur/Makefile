PORTNAME=	profiteur
PORTVERSION=	0.4.6.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files
WWW=		https://github.com/jaspervdj/profiteur

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.1.0 \
		assoc-1.0.2_3 \
		attoparsec-0.14.4_2 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		bifunctors-5.5.13 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		generically-0.1 \
		ghc-prof-1.4.1.11 \
		hashable-1.4.1.0 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		js-jquery-3.3.1 \
		primitive-0.7.4.0 \
		random-1.2.1.1 \
		scientific-0.3.7.0_3 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		splitmix-0.1.0.4_1 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_3 \
		text-short-0.1.5_1 \
		th-abstraction-0.4.5.0 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1_1 \
		uuid-types-1.0.5_3 \
		vector-0.12.3.1_2 \
		witherable-0.4.2_3

CABAL_WRAPPER_SCRIPTS=		${CABAL_EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
