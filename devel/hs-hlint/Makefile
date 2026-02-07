PORTNAME=	hlint
PORTVERSION=	3.10
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Source code suggestions
WWW=		https://github.com/ndmitchell/hlint

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_LOCALE=	C.UTF-8
USE_CABAL=	OneTuple-0.4.2_1 \
		QuickCheck-2.15.0.1_1 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_3 \
		alex-3.5.3.0 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		assoc-1.1.1_1 \
		attoparsec-0.14.4_6 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		bitvec-1.1.5.0_3 \
		character-ps-0.1 \
		clock-0.8.4 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		conduit-1.3.6.1 \
		contravariant-1.5.5 \
		cpphs-1.20.9.1_1 \
		data-default-0.8.0.1 \
		data-fix-0.3.4_1 \
		deriving-aeson-0.2.10 \
		directory-1.3.9.0_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		extra-1.8 \
		file-embed-0.0.16.0 \
		file-io-0.1.5 \
		filepath-1.5.4.0 \
		filepattern-0.1.3 \
		generically-0.1.1_4 \
		ghc-lib-parser-9.12.2.20250421 \
		ghc-lib-parser-ex-9.12.0.0 \
		happy-2.1.5 \
		happy-lib-2.1.5 \
		hashable-1.5.0.0_1 \
		hscolour-1.25 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		libyaml-0.1.4 \
		libyaml-clib-0.2.5 \
		mono-traversable-1.0.21.0 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		polyparse-1.13_9 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		process-1.6.26.0 \
		random-1.3.1 \
		refact-0.3.0.2 \
		resourcet-1.3.0 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		split-0.2.5 \
		splitmix-0.1.1 \
		strict-0.5.1_1 \
		syb-0.7.2.4 \
		tagged-0.8.9 \
		tasty-1.5.3_1 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-compat-0.7.2 \
		uniplate-1.6.13_1 \
		unix-2.8.7.0 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_1 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_3 \
		witherable-0.5_1 \
		yaml-0.11.11.2_2

post-patch:
	${REINPLACE_CMD} 's|jobs: 1|jobs: 2|' ${CABAL_HOME}/.cabal/config

.include <bsd.port.mk>
