PORTNAME=	profiteur
DISTVERSION=	0.4.7.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files
WWW=		https://github.com/jaspervdj/profiteur/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.4.8:lang/ghc94

USES=		cabal

USE_CABAL=	OneTuple-0.4.2 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_4 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		assoc-1.1.1 \
		attoparsec-0.14.4_5 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.2 \
		bifunctors-5.6.2 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-fix-0.3.4 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		foldable1-classes-compat-0.1_6 \
		generically-0.1.1_4 \
		ghc-prof-1.4.1.12 \
		hashable-1.4.4.0_1 \
		indexed-traversable-0.1.4 \
		indexed-traversable-instances-0.1.2 \
		integer-logarithms-1.0.3.1_6 \
		js-jquery-3.3.1 \
		optparse-applicative-0.18.1.0 \
		os-string-2.0.7 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.8.0.0_1 \
		random-1.2.1.2 \
		scientific-0.3.7.0_7 \
		semialign-1.3.1_1 \
		semigroupoids-6.0.1_1 \
		splitmix-0.1.0.5_1 \
		strict-0.5_1 \
		tagged-0.8.8_1 \
		tasty-1.5.2 \
		text-short-0.1.6_2 \
		th-abstraction-0.5.0.0 \
		these-1.2.1_1 \
		time-compat-1.9.7_2 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_3 \
		uuid-types-1.0.6_1 \
		vector-0.13.2.0 \
		vector-stream-0.1.0.1_2 \
		witherable-0.4.2_5

CABAL_WRAPPER_SCRIPTS=		${CABAL_EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.3.1/javascript/jquery-3.3.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
