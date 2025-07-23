PORTNAME=	koka
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
CATEGORIES=	lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Koka: strongly typed functional-style language with effect inference
WWW=		https://koka-lang.github.io/koka/doc/index.html

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	koka-lang
GH_TUPLE=	microsoft:mimalloc:10efe29:mimalloc/kklib/mimalloc

CABAL_FLAGS=	-relocatable

USE_CABAL=	Diff-1.0.2 \
		FloatingHex-0.5 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		StateVar-1.2.2 \
		adjunctions-4.4.3 \
		aeson-2.2.3.0_4 \
		alex-3.5.3.0 \
		ansi-terminal-1.1.3 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		base-compat-0.14.1 \
		base-orphans-0.9.3 \
		basement-0.0.16 \
		bifunctors-5.6.2_2 \
		boring-0.2.2_1 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		clock-0.8.4 \
		co-log-core-0.3.2.5 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		data-default-0.8.0.1 \
		data-fix-0.3.4_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		extra-1.8 \
		file-embed-0.0.16.0 \
		free-5.2_7 \
		generic-arbitrary-1.0.1.2 \
		generic-lens-2.2.2.0_1 \
		generic-lens-core-2.2.1.0_2 \
		generically-0.1.1_4 \
		hashable-1.5.0.0_1 \
		hsc2hs-0.68.10_4 \
		indexed-profunctors-0.1.1.1 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		invariant-0.6.4_1 \
		isocline-1.0.9 \
		kan-extensions-5.2.7 \
		lens-5.3.5 \
		lens-aeson-1.2.3_2 \
		lsp-2.7.0.1_1 \
		lsp-types-2.3.0.1 \
		mod-0.2.0.1_1 \
		network-3.2.7.0 \
		network-bsd-2.8.1.0_6 \
		network-simple-0.4.5 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.19.0.0 \
		os-string-2.0.7_1 \
		parallel-3.2.2.0_9 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		profunctors-5.6.3 \
		quickcheck-instances-0.3.33_1 \
		random-1.3.1 \
		reflection-2.1.9_1 \
		regex-1.1.0.2 \
		regex-base-0.94.0.3 \
		regex-pcre-builtin-0.95.2.3.8.44_6 \
		regex-tdfa-1.3.2.4 \
		row-types-1.0.1.2_1 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		semigroups-0.20 \
		semirings-0.7 \
		socks-0.6.1 \
		some-1.0.6_2 \
		sorted-list-0.3.1.0 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_2 \
		text-iso8601-0.1.1_2 \
		text-rope-0.3 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		time-locale-compat-0.1.1.5 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unliftio-0.2.25.1 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_1 \
		vector-stream-0.1.0.1_3 \
		void-0.7.3 \
		witherable-0.5_1

CABAL_EXECUTABLES=	${PORTNAME}
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

PLIST_SUB+=	VER=${DISTVERSIONFULL}

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL} && \
		${COPYTREE_SHARE} kklib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL}

.include <bsd.port.mk>
