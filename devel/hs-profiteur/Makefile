PORTNAME=	profiteur
PORTVERSION=	0.4.7.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files
WWW=		https://github.com/jaspervdj/profiteur

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		assoc-1.1_1 \
		attoparsec-0.14.4_5 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.1 \
		bifunctors-5.6.2 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-array-byte-0.1.0.1_3 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		foldable1-classes-compat-0.1_4 \
		generically-0.1.1_2 \
		ghc-prof-1.4.1.12 \
		hashable-1.4.3.0_1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-logarithms-1.0.3.1_5 \
		js-jquery-3.3.1 \
		primitive-0.8.0.0_1 \
		random-1.2.1.2 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.5.0.0 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_1 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0_1 \
		vector-stream-0.1.0.1_1 \
		witherable-0.4.2_4


CABAL_WRAPPER_SCRIPTS=		${CABAL_EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
