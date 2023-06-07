PORTNAME=	verismith
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0.2-39
DISTVERSIONSUFFIX=	-g2523998
CATEGORIES=	cad haskell

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	ea76f79b0b3366ab376b75ec8e7894ee5fccdc55.patch:-p1 # https://github.com/ymherklotz/verismith/pull/86

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Verilog fuzzer
WWW=		https://github.com/ymherklotz/verismith

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal

USE_CABAL=	OneTuple-0.3.1_3 \
		StateVar-1.2.2 \
		adjunctions-4.4.2 \
		alex-3.2.7.1 \
		ansi-terminal-0.11.4 \
		ansi-wl-pprint-0.6.9_3 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		barbies-2.0.4.0 \
		base-compat-0.12.2 \
		base-orphans-0.8.7 \
		basement-0.0.15 \
		bifunctors-5.5.14 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_3 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		concurrent-output-1.10.17 \
		constraints-0.13.4 \
		contravariant-1.5.5 \
		cryptonite-0.30 \
		data-array-byte-0.1.0.1_1 \
		data-fix-0.3.2_3 \
		directory-1.3.7.1 \
		distributive-0.6.2.1_1 \
		dotgen-0.4.3 \
		enclosed-exceptions-1.0.3 \
		erf-2.0.0.0 \
		fgl-5.7.0.3_1 \
		fgl-visualize-0.1.0.1 \
		free-5.1.10 \
		gitrev-1.3.1 \
		happy-1.20.1.1 \
		hashable-1.4.2.0 \
		haskell-lexer-1.1.1 \
		hedgehog-1.1.2 \
		hsc2hs-0.68.9 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_4 \
		invariant-0.6_1 \
		kan-extensions-5.2.5 \
		lens-5.1.1_1 \
		lifted-async-0.10.2.3 \
		lifted-base-0.2.3.12 \
		megaparsec-9.2.2 \
		memory-0.17.0_1 \
		mmorph-1.2.0_3 \
		monad-control-1.0.3.1 \
		optparse-applicative-0.16.1.0_2 \
		parallel-3.2.2.0_5 \
		parser-combinators-1.3.0 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		primitive-0.7.4.0_1 \
		process-1.6.17.0 \
		profunctors-5.6.2_2 \
		random-1.2.1.1 \
		recursion-schemes-5.2.2.3 \
		reflection-2.1.6_1 \
		resourcet-1.2.6 \
		scientific-0.3.7.0_3 \
		selective-0.5 \
		semigroupoids-5.3.7_1 \
		semigroups-0.20 \
		shelly-1.10.0.1 \
		splitmix-0.1.0.4_2 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_3 \
		terminal-size-0.3.3 \
		th-abstraction-0.4.5.0 \
		these-1.1.1.1_6 \
		time-1.12.2 \
		tomland-1.3.3.2 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_4 \
		unix-2.7.3 \
		unix-compat-0.6_1 \
		unliftio-core-0.2.1.0_1 \
		unordered-containers-0.2.19.1_1 \
		validation-selective-0.1.0.2 \
		vector-0.13.0.0_2 \
		vector-stream-0.1.0.0_2 \
		void-0.7.3 \
		wl-pprint-annotated-0.1.0.1_1

USE_GITHUB=	yes
GH_ACCOUNT=	ymherklotz

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent fpga20

.include <bsd.port.mk>
