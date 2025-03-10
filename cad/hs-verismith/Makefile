PORTNAME=	verismith
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0.2-40
DISTVERSIONSUFFIX=	-g866707b
CATEGORIES=	cad haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Verilog fuzzer
WWW=		https://github.com/ymherklotz/verismith/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	ymherklotz

USE_CABAL=	OneTuple-0.4.2 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_2 \
		alex-3.5.1.0 \
		ansi-terminal-1.1.1 \
		ansi-terminal-types-1.1 \
		assoc-1.1.1 \
		async-2.2.5_2 \
		barbies-2.1.1.0 \
		base-compat-0.14.0 \
		base-orphans-0.9.2 \
		basement-0.0.16 \
		bifunctors-5.6.2 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		boring-0.2.2 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		concurrent-output-1.10.21 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		cryptonite-0.30 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.4 \
		distributive-0.6.2.1_1 \
		dotgen-0.4.3 \
		enclosed-exceptions-1.0.3 \
		erf-2.0.0.0 \
		fgl-5.8.2.0 \
		fgl-visualize-0.1.0.1 \
		free-5.2_5 \
		gitrev-1.3.1 \
		happy-1.20.1.1 \
		hashable-1.4.7.0 \
		haskell-lexer-1.1.1 \
		hedgehog-1.4_8 \
		hsc2hs-0.68.10_2 \
		indexed-traversable-0.1.4 \
		indexed-traversable-instances-0.1.2 \
		integer-logarithms-1.0.3.1_6 \
		invariant-0.6.3 \
		kan-extensions-5.2.6 \
		lens-5.2.3_5 \
		lifted-async-0.10.2.5_1 \
		lifted-base-0.2.3.12 \
		math-functions-0.3.4.4 \
		megaparsec-9.6.1 \
		memory-0.18.0 \
		mmorph-1.2.0_3 \
		monad-control-1.0.3.1 \
		mwc-probability-2.3.1 \
		mwc-random-0.15.1.0 \
		optparse-applicative-0.18.1.0 \
		os-string-2.0.6 \
		parallel-3.2.2.0_8 \
		parser-combinators-1.3.0_1 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_1 \
		profunctors-5.6.2_3 \
		random-1.2.1.2 \
		recursion-schemes-5.2.3 \
		reflection-2.1.8 \
		resourcet-1.3.0 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.0_1 \
		selective-0.7.0.1 \
		semigroupoids-6.0.1_1 \
		semigroups-0.20 \
		shelly-1.12.1_1 \
		splitmix-0.1.0.5_1 \
		strict-0.5.1_1 \
		tagged-0.8.8_1 \
		terminal-size-0.3.4_1 \
		th-abstraction-0.7.0.0 \
		these-1.2.1_1 \
		tomland-1.3.3.3 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unix-compat-0.7.2 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_3 \
		validation-selective-0.2.0.0_4 \
		vector-0.13.1.0_1 \
		vector-stream-0.1.0.1_1 \
		void-0.7.3 \
		wl-pprint-annotated-0.1.0.1_3

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent fpga20

.include <bsd.port.mk>
