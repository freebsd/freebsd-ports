PORTNAME=	stack
PORTVERSION=	2.7.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-8.10.7:lang/ghc810
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake \
		${LOCALBASE}/lib/compat/libffi.so.6:devel/libffi321 \
		${LOCALBASE}/lib/compat/libffi.so.7:devel/libffi33

USES=		cabal gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	commercialhaskell
USE_PERL5=	run
# src/Stack/Constants.hs has hard-coded "ghc" invocation in the Template Haskell splice
BINARY_ALIAS=	ghc=ghc-8.10.7

CABAL_FLAGS=	-support_aesni

USE_CABAL=	Cabal-syntax-3.6.0.0 \
		Glob-0.10.2_3 \
		OneTuple-0.3.1_2 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-1.5.6.0_5 \
		annotated-wl-pprint-0.7.0_1 \
		ansi-terminal-0.11.3 \
		ansi-wl-pprint-0.6.9_3 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_2 \
		async-2.2.4_1 \
		attoparsec-0.14.4_1 \
		attoparsec-iso8601-1.1.0.0 \
		auto-update-0.1.6 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1_2 \
		base-orphans-0.8.6 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.14 \
		bifunctors-5.5.12 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_2 \
		byteorder-1.0.4 \
		casa-client-0.0.1 \
		casa-types-0.0.2 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.2_1 \
		clock-0.8.3 \
		cmdargs-0.10.21 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.2 \
		conduit-combinators-1.3.0 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.5 \
		cryptohash-sha256-0.11.102.1 \
		cryptonite-0.30 \
		cryptonite-conduit-0.2.2_1 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_2 \
		digest-0.0.1.3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		easy-file-0.2.2 \
		echo-0.1.4 \
		ed25519-0.0.5.0_5 \
		extra-1.7.10 \
		fast-logger-3.1.1 \
		file-embed-0.0.15.0 \
		filelock-0.1.1.5 \
		fsnotify-0.3.0.1_2 \
		generic-deriving-1.14.1 \
		githash-0.1.6.2 \
		hackage-security-0.6.2.1_2 \
		hashable-1.3.5.0_1 \
		hi-file-parser-0.1.2.0_1 \
		hourglass-0.2.12 \
		hpack-0.35.0 \
		hsc2hs-0.68.8 \
		http-api-data-0.5 \
		http-client-0.7.11_1 \
		http-client-tls-0.3.6.1 \
		http-conduit-2.3.8 \
		http-download-0.2.0.0 \
		http-types-0.12.3 \
		indexed-traversable-0.1.2_1 \
		indexed-traversable-instances-0.1.1_1 \
		infer-license-0.2.0 \
		integer-logarithms-1.0.3.1_2 \
		iproute-1.7.12 \
		libyaml-0.1.2 \
		lift-type-0.1.0.1 \
		lifted-base-0.2.3.12 \
		lukko-0.1.1.3_2 \
		megaparsec-9.2.1 \
		memory-0.17.0 \
		microlens-0.4.13.0 \
		microlens-mtl-0.2.0.2 \
		microlens-th-0.4.3.10 \
		mime-types-0.1.0.9 \
		mintty-0.1.4 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.36_2 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		mtl-compat-0.2.2 \
		mustache-2.4.1 \
		neat-interpolation-0.5.1.3 \
		network-3.1.2.7 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.17.0.0 \
		optparse-simple-0.1.1.4 \
		pantry-0.5.5 \
		parser-combinators-1.3.0 \
		path-0.9.2 \
		path-io-1.7.0 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.13.3.5_1 \
		persistent-sqlite-2.13.1.0 \
		persistent-template-2.12.0.0 \
		primitive-0.7.4.0 \
		project-template-0.2.1.0 \
		random-1.2.1.1 \
		resource-pool-0.3.1.0 \
		resourcet-1.2.6 \
		retry-0.9.2.1 \
		rio-0.1.22.0 \
		rio-orphans-0.1.2.0 \
		rio-prettyprint-0.1.1.0 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.3 \
		scientific-0.3.7.0_2 \
		semialign-1.2.0.1_2 \
		semigroupoids-5.3.7 \
		semigroups-0.20 \
		silently-1.2.5.2 \
		socks-0.6.1 \
		split-0.2.3.4_2 \
		splitmix-0.1.0.4 \
		stm-chans-3.0.0.6 \
		streaming-commons-0.2.2.4 \
		strict-0.4.0.1_4 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_2 \
		tar-0.5.1.1_5 \
		tar-conduit-0.3.2 \
		temporary-1.3 \
		text-metrics-0.3.2 \
		text-short-0.1.5 \
		th-abstraction-0.4.3.0 \
		th-compat-0.1.3_1 \
		th-expand-syns-0.4.9.0 \
		th-lift-0.8.2_1 \
		th-lift-instances-0.1.19 \
		th-reify-many-0.1.10 \
		these-1.1.1.1_5 \
		time-compat-1.9.6.1_3 \
		tls-1.6.0 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.10.1 \
		unicode-data-0.3.0_1 \
		unicode-transforms-0.4.0.1 \
		unix-compat-0.6 \
		unix-time-0.4.7 \
		unliftio-0.2.22.0 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.19.1 \
		uuid-types-1.0.5_2 \
		vault-0.3.1.5_1 \
		vector-0.12.3.1_2 \
		vector-algorithms-0.8.0.4_2 \
		witherable-0.4.2_3 \
		x509-1.7.7 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		yaml-0.11.8.0 \
		zip-archive-0.4.2.1 \
		zlib-0.6.3.0

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# Keep it in sync with LLVM_VERSION in lang/ghc* port, which is used to build this one
LLVM_VERSION=	10
RUN_DEPENDS+=	llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
.endif

.if ${OSVERSION} >= 1300078 && ${ARCH} != powerpc64
LIB_DEPENDS+=	libncursesw.so.8:misc/compat12x
.endif

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.post.mk>
