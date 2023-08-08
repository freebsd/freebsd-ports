PORTNAME=	profiteur
PORTVERSION=	0.4.6.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files
WWW=		https://github.com/jaspervdj/profiteur

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		assoc-1.1 \
		attoparsec-0.14.4_3 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		bifunctors-5.6.1 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_4 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		foldable1-classes-compat-0.1_2 \
		generically-0.1.1_1 \
		ghc-prof-1.4.1.12 \
		hashable-1.4.2.0_1 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		js-jquery-3.3.1 \
		primitive-0.8.0.0 \
		random-1.2.1.1 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		splitmix-0.1.0.4_2 \
		strict-0.5 \
		tagged-0.8.7 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1_2 \
		uuid-types-1.0.5_4 \
		vector-0.12.3.1_4 \
		witherable-0.4.2_4

CABAL_REVISION=			1
CABAL_WRAPPER_SCRIPTS=		${CABAL_EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
