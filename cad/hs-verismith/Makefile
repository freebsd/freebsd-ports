PORTNAME=	verismith
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	cad haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Verilog fuzzer
WWW=		https://github.com/ymherklotz/verismith/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

xBUILD_DEPENDS=	ghc-9.6.7:lang/ghc96

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	ymherklotz

USE_CABAL=	OneTuple-0.4.2_1 \
		StateVar-1.2.2 \
		adjunctions-4.4.3 \
		alex-3.5.3.0 \
		ansi-terminal-1.1.3 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		barbies-2.1.1.0 \
		base-compat-0.14.1 \
		base-orphans-0.9.3 \
		basement-0.0.16 \
		bifunctors-5.6.2_2 \
		binary-0.8.9.3 \
		blaze-builder-0.4.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		boring-0.2.2_1 \
		bytestring-0.11.5.4 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		concurrent-output-1.10.21 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		cryptonite-0.30 \
		data-default-0.8.0.1 \
		data-default-class-0.2.0.0 \
		data-fix-0.3.4_1 \
		directory-1.3.9.0_1 \
		distributive-0.6.2.1_1 \
		dotgen-0.4.3 \
		enclosed-exceptions-1.0.3 \
		erf-2.0.0.0 \
		fgl-5.8.3.0 \
		fgl-visualize-0.1.0.1 \
		file-io-0.1.5 \
		filepath-1.4.301.0_1 \
		free-5.2_7 \
		gitrev-1.3.1 \
		happy-2.1.6 \
		happy-lib-2.1.6 \
		hashable-1.5.0.0_1 \
		haskell-lexer-1.2.1 \
		hedgehog-1.5_2 \
		hsc2hs-0.68.10_4 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-logarithms-1.0.4 \
		invariant-0.6.4_1 \
		kan-extensions-5.2.7 \
		lens-5.3.5 \
		lifted-async-0.10.2.7 \
		lifted-base-0.2.3.12 \
		math-functions-0.3.4.4 \
		megaparsec-9.7.0 \
		memory-0.18.0_1 \
		mmorph-1.2.1 \
		monad-control-1.0.3.1 \
		mwc-probability-2.3.1 \
		mwc-random-0.15.2.0 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7_1 \
		parallel-3.2.2.0_9 \
		parsec-3.1.18.0 \
		parser-combinators-1.3.0_1 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		process-1.6.26.1 \
		profunctors-5.6.3 \
		random-1.2.1.3 \
		recursion-schemes-5.2.3_1 \
		reflection-2.1.9_1 \
		resourcet-1.3.0 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.0_2 \
		selective-0.7.0.1 \
		semigroupoids-6.0.1_2 \
		semigroups-0.20 \
		shelly-1.12.1_1 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_2 \
		terminal-size-0.3.4_1 \
		text-2.1.2_1 \
		th-abstraction-0.7.1.0_1 \
		these-1.2.1_2 \
		tomland-1.3.3.3_2 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unix-2.8.7.0_1 \
		unix-compat-0.7.4 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		validation-selective-0.2.0.0_5 \
		vector-0.13.2.0_1 \
		vector-stream-0.1.0.1_3 \
		void-0.7.3 \
		wl-pprint-annotated-0.1.0.1_4

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent fpga20

.include <bsd.port.mk>
