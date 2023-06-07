PORTNAME=	elm-format
PORTVERSION=	0.8.7
CATEGORIES=	devel textproc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide
WWW=		https://github.com/avh4/elm-format/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	avh4

USE_CABAL=	HUnit-1.6.2.0 \
		OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_4 \
		assoc-1.1 \
		attoparsec-0.14.4_3 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		bifunctors-5.6.1 \
		bimap-0.5.0 \
		bitvec-1.1.4.0 \
		call-stack-0.4.0 \
		clock-0.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		concurrent-split-0.0.1.1 \
		conduit-1.3.4.3_1 \
		contravariant-1.5.5 \
		data-array-byte-0.1.0.1_1 \
		data-fix-0.3.2_4 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		extra-1.7.13 \
		filepattern-0.1.3 \
		foldable1-classes-compat-0.1_2 \
		generically-0.1.1_1 \
		hashable-1.4.2.0_1 \
		haskell-lexer-1.1.1 \
		heaps-0.4 \
		hspec-2.11.0.1 \
		hspec-core-2.11.0.1 \
		hspec-discover-2.11.0.1 \
		hspec-expectations-0.8.2 \
		hspec-golden-0.2.1.0 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		js-dgtable-0.5.2 \
		js-flot-0.8.3 \
		js-jquery-3.3.1 \
		libyaml-0.1.2_1 \
		mono-traversable-1.0.15.3 \
		optparse-applicative-0.17.0.0 \
		pooled-io-0.0.2.3 \
		primitive-0.8.0.0 \
		quickcheck-io-0.2.0 \
		random-1.2.1.1 \
		relude-1.1.0.0 \
		resourcet-1.3.0 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		shake-0.19.7_1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		strict-0.5 \
		tagged-0.8.7 \
		tasty-1.4.3 \
		tasty-hunit-0.10.0.3 \
		text-2.0.2 \
		text-short-0.1.5_2 \
		tf-random-0.5 \
		th-abstraction-0.5.0.0 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		transformers-compat-0.7.2 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		unsafe-0.0 \
		utf8-string-1.0.2 \
		utility-ht-0.0.17 \
		uuid-types-1.0.5_4 \
		vector-0.13.0.0_3 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_2 \
		witherable-0.4.2_4 \
		yaml-0.11.11.0

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
