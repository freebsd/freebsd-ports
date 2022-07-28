PORTNAME=	profiteur
PORTVERSION=	0.4.6.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	OneTuple-0.3.1_2 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.0.0_1 \
		assoc-1.0.2_2 \
		attoparsec-0.14.4_1 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1_2 \
		base-orphans-0.8.6 \
		bifunctors-5.5.12 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_2 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		generically-0.1 \
		ghc-prof-1.4.1.11 \
		hashable-1.4.0.2 \
		indexed-traversable-0.1.2_1 \
		indexed-traversable-instances-0.1.1_1 \
		integer-logarithms-1.0.3.1_2 \
		js-jquery-3.3.1 \
		primitive-0.7.4.0 \
		random-1.2.1.1 \
		scientific-0.3.7.0_2 \
		semialign-1.2.0.1_2 \
		semigroupoids-5.3.7 \
		splitmix-0.1.0.4 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_2 \
		text-short-0.1.5 \
		th-abstraction-0.4.3.0 \
		these-1.1.1.1_5 \
		time-compat-1.9.6.1_3 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1 \
		uuid-types-1.0.5_2 \
		vector-0.12.3.1_2 \
		witherable-0.4.2_3

CABAL_WRAPPER_SCRIPTS=		${EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
