PORTNAME=	koka
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.3
CATEGORIES=	lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Koka: strongly typed functional-style language with effect inference
WWW=		https://koka-lang.github.io/koka/doc/index.html \
		https://github.com/koka-lang/koka

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	koka-lang
GH_TUPLE=	microsoft:mimalloc:10efe29:mimalloc/kklib/mimalloc

CABAL_FLAGS=	-relocatable

USE_CABAL=	Diff-1.0.2 \
		FloatingHex-0.5 \
		OneTuple-0.4.2.1 \
		QuickCheck-2.18.0.0 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		adjunctions-4.4.4 \
		aeson-2.2.4.1 \
		alex-3.5.4.2 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_2 \
		async-2.2.6 \
		attoparsec-0.14.4_6 \
		base-compat-0.15.0 \
		base-orphans-0.9.4 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.3_1 \
		boring-0.2.2_1 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		clock-0.8.4 \
		co-log-core-0.3.2.6 \
		colour-2.3.7 \
		comonad-5.0.10 \
		constraints-0.14.4 \
		contravariant-1.5.6 \
		data-default-0.8.0.2 \
		data-fix-0.3.4_2 \
		distributive-0.6.3 \
		dlist-1.0_2 \
		entropy-0.4.1.11_1 \
		extra-1.8.1 \
		file-embed-0.0.16.0 \
		free-5.2_8 \
		generic-arbitrary-1.0.1.2 \
		generic-lens-2.3.0.0 \
		generic-lens-core-2.3.0.0 \
		hashable-1.5.1.0 \
		hsc2hs-0.68.10_5 \
		indexed-profunctors-0.1.1.1 \
		indexed-traversable-0.1.4_2 \
		indexed-traversable-instances-0.1.2.1 \
		integer-conversion-0.1.1_2 \
		integer-logarithms-1.0.5 \
		invariant-0.6.5 \
		isocline-1.1.0 \
		kan-extensions-5.2.8 \
		lens-5.3.6 \
		lens-aeson-1.2.3_2 \
		lsp-2.8.0.0 \
		lsp-types-2.4.0.0 \
		mod-0.2.1.0 \
		network-3.2.8.0 \
		network-bsd-2.8.1.0_6 \
		network-simple-0.4.5 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.1.0 \
		optparse-applicative-0.19.0.0 \
		parallel-3.3.0.0_1 \
		prettyprinter-1.7.2 \
		prettyprinter-ansi-terminal-1.1.4 \
		primitive-0.9.1.0_1 \
		profunctors-5.6.3 \
		quickcheck-instances-0.4_2 \
		random-1.3.1 \
		reflection-2.1.9_1 \
		regex-1.1.0.2 \
		regex-base-0.94.0.3 \
		regex-pcre-builtin-0.95.2.3.8.44_7 \
		regex-tdfa-1.3.2.5 \
		row-types-1.0.1.2_1 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.1 \
		semialign-1.3.1.1 \
		semigroupoids-6.0.2_1 \
		semirings-0.7 \
		socks-0.6.1 \
		some-1.0.6_3 \
		sorted-list-0.3.1.0 \
		splitmix-0.1.3.2 \
		streaming-commons-0.2.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.10_1 \
		tasty-1.5.4 \
		text-iso8601-0.1.1.1 \
		text-rope-0.3 \
		text-short-0.1.6.1 \
		th-abstraction-0.7.2.0 \
		th-compat-0.1.7 \
		these-1.2.1_3 \
		time-compat-1.9.9_1 \
		time-locale-compat-0.1.1.5 \
		transformers-base-0.4.6.1 \
		transformers-compat-0.8 \
		unliftio-0.2.25.1 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6.1 \
		vector-0.13.2.0_2 \
		vector-stream-0.1.0.1_4 \
		websockets-0.13.0.0_6 \
		witherable-0.5_2 \
		zlib-0.7.1.1

CABAL_EXECUTABLES=	${PORTNAME}
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

PLIST_SUB+=	VER=${DISTVERSIONFULL}

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL} && \
		${COPYTREE_SHARE} kklib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL}

.include <bsd.port.mk>
