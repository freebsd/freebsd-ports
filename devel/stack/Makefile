PORTNAME=	stack
PORTVERSION=	2.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs
WWW=		https://www.haskellstack.org/

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=	compiler crashes

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake \
		${LOCALBASE}/lib/compat/libffi.so.6:devel/libffi321 \
		${LOCALBASE}/lib/compat/libffi.so.7:devel/libffi33

USES=		cabal gmake iconv:wchar_t perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	commercialhaskell
USE_PERL5=	run

CABAL_FLAGS=	-support_aesni
CABAL_PROJECT=	remove

USE_CABAL=	Glob-0.10.2_3 \
		OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		annotated-wl-pprint-0.7.0_1 \
		ansi-terminal-1.0 \
		ansi-terminal-types-0.11.5_1 \
		ansi-wl-pprint-0.6.9_4 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1 \
		async-2.2.4_3 \
		attoparsec-0.14.4_3 \
		attoparsec-iso8601-1.1.0.0_1 \
		auto-update-0.1.6 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.15 \
		bifunctors-5.6.1 \
		bitvec-1.1.4.0 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_4 \
		byteorder-1.0.4 \
		casa-client-0.0.1 \
		casa-types-0.0.2 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		clock-0.8.3 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		conduit-combinators-1.3.0 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.6 \
		cryptohash-sha256-0.11.102.1_2 \
		cryptonite-0.30 \
		cryptonite-conduit-0.2.2_1 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_4 \
		digest-0.0.1.7 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		easy-file-0.2.5 \
		echo-0.1.4 \
		ed25519-0.0.5.0_7 \
		extra-1.7.13 \
		fast-logger-3.2.1 \
		file-embed-0.0.15.0 \
		filelock-0.1.1.6 \
		foldable1-classes-compat-0.1_2 \
		fsnotify-0.4.1.0 \
		generic-deriving-1.14.4 \
		generically-0.1.1_1 \
		githash-0.1.6.3 \
		hackage-security-0.6.2.3_3 \
		hashable-1.4.2.0_1 \
		hi-file-parser-0.1.4.0 \
		hourglass-0.2.12 \
		hpack-0.35.2_1 \
		hsc2hs-0.68.9 \
		http-api-data-0.5.1 \
		http-client-0.7.13.1_1 \
		http-client-tls-0.3.6.1 \
		http-conduit-2.3.8 \
		http-download-0.2.0.0 \
		http-types-0.12.3 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		infer-license-0.2.0 \
		integer-logarithms-1.0.3.1_4 \
		iproute-1.7.12 \
		libyaml-0.1.2_1 \
		lift-type-0.1.1.1 \
		lifted-base-0.2.3.12 \
		lukko-0.1.1.3_4 \
		megaparsec-9.3.1 \
		memory-0.18.0 \
		microlens-0.4.13.1 \
		microlens-mtl-0.2.0.3 \
		microlens-th-0.4.3.13 \
		mime-types-0.1.1.0 \
		mintty-0.1.4 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.39_1 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		mtl-compat-0.2.2 \
		mustache-2.4.2 \
		neat-interpolation-0.5.1.3 \
		network-3.1.3.0 \
		network-uri-2.6.4.2 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.17.0.0 \
		optparse-simple-0.1.1.4 \
		pantry-0.8.2.2 \
		parser-combinators-1.3.0 \
		path-0.9.2 \
		path-io-1.8.1 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.14.5.0 \
		persistent-sqlite-2.13.1.1 \
		persistent-template-2.12.0.0 \
		primitive-0.8.0.0 \
		project-template-0.2.1.0 \
		random-1.2.1.1 \
		resource-pool-0.4.0.0 \
		resourcet-1.3.0 \
		retry-0.9.3.1 \
		rio-0.1.22.0 \
		rio-orphans-0.1.2.0 \
		rio-prettyprint-0.1.4.0 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.3 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		semigroups-0.20 \
		silently-1.2.5.3 \
		socks-0.6.1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		stm-chans-3.0.0.9 \
		streaming-commons-0.2.2.6 \
		strict-0.5 \
		syb-0.7.2.3 \
		tagged-0.8.7 \
		tar-0.5.1.1_6 \
		tar-conduit-0.3.2 \
		temporary-1.3 \
		text-metrics-0.3.2_2 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		th-compat-0.1.4_2 \
		th-expand-syns-0.4.11.0_1 \
		th-lift-0.8.3 \
		th-lift-instances-0.1.20 \
		th-reify-many-0.1.10 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		tls-1.6.0 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.0 \
		unicode-data-0.4.0.1_1 \
		unicode-transforms-0.4.0.1_3 \
		unix-compat-0.7 \
		unix-time-0.4.9 \
		unliftio-0.2.24.0 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		uuid-types-1.0.5_4 \
		vault-0.3.1.5_3 \
		vector-0.13.0.0_3 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_2 \
		witherable-0.4.2_4 \
		x509-1.7.7 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		yaml-0.11.11.0 \
		zip-archive-0.4.3 \
		zlib-0.6.3.0_1

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# Keep it in sync with LLVM_VERSION in lang/ghc* port, which is used to build this one
LLVM_VERSION=	10
RUN_DEPENDS+=	llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
.endif

.if ${ARCH} != powerpc64
LIB_DEPENDS+=	libncursesw.so.8:misc/compat12x
.endif

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.post.mk>
