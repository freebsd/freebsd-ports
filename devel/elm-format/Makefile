PORTNAME=	elm-format
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
DISTVERSIONSUFFIX=	-gc99aa91
PORTREVISION=	1
CATEGORIES=	devel textproc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide
WWW=		https://github.com/avh4/elm-format/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.4.8:lang/ghc94

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	avh4

USE_CABAL=	HUnit-1.6.2.0 \
		OneTuple-0.4.2 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_4 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_4 \
		assoc-1.1.1 \
		attoparsec-0.14.4_5 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.2 \
		bifunctors-5.6.2 \
		bimap-0.5.0 \
		bitvec-1.1.5.0_1 \
		call-stack-0.4.0 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		concurrent-split-0.0.1.1 \
		conduit-1.3.6 \
		contravariant-1.5.5 \
		data-fix-0.3.4 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		extra-1.8 \
		filepattern-0.1.3 \
		foldable1-classes-compat-0.1_6 \
		generically-0.1.1_4 \
		hashable-1.4.4.0_1 \
		haskell-lexer-1.1.2 \
		heaps-0.4 \
		hspec-2.11.10 \
		hspec-core-2.11.10 \
		hspec-discover-2.11.10 \
		hspec-expectations-0.8.4_2 \
		hspec-golden-0.2.1.0 \
		indexed-traversable-0.1.4 \
		indexed-traversable-instances-0.1.2 \
		integer-logarithms-1.0.3.1_6 \
		js-dgtable-0.5.2 \
		js-flot-0.8.3 \
		js-jquery-3.3.1 \
		libyaml-0.1.4 \
		libyaml-clib-0.2.5 \
		mono-traversable-1.0.20.0 \
		optparse-applicative-0.17.1.0_1 \
		os-string-2.0.7 \
		pooled-io-0.0.2.3_1 \
		primitive-0.8.0.0_1 \
		quickcheck-io-0.2.0 \
		random-1.2.1.2 \
		relude-1.2.2.0 \
		resourcet-1.3.0 \
		scientific-0.3.7.0_7 \
		semialign-1.3.1_1 \
		semigroupoids-6.0.1_1 \
		shake-0.19.8 \
		split-0.2.5 \
		splitmix-0.1.0.5_1 \
		strict-0.5_1 \
		tagged-0.8.8_1 \
		tasty-1.5.2 \
		tasty-hunit-0.10.2 \
		text-short-0.1.6_2 \
		tf-random-0.5 \
		th-abstraction-0.5.0.0 \
		these-1.2.1_1 \
		time-compat-1.9.7_2 \
		transformers-compat-0.7.2 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_3 \
		unsafe-0.0 \
		utf8-string-1.0.2 \
		utility-ht-0.0.17.2 \
		uuid-types-1.0.6_1 \
		vector-0.13.2.0 \
		vector-algorithms-0.9.0.3 \
		vector-stream-0.1.0.1_2 \
		witherable-0.4.2_5 \
		yaml-0.11.11.2_2

CABAL_PROJECT=	append

post-extract:
	${RM} ${WRKSRC}/cabal.project.freeze
	${ECHO} "module Build_elm_format where" > ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe :: String" >> ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe = \"${PORTNAME}\"" >> ${WRKSRC}/src/Build_elm_format.hs

post-patch:
	@${REINPLACE_CMD} -e '/with-compiler: ghc-/d' \
		${WRKSRC}/cabal.project || ${TRUE}

.include <bsd.port.mk>
