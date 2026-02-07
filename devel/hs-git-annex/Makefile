PORTNAME=	git-annex
DISTVERSION=	10.20251215
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git
WWW=		https://git-annex.branchable.com/

LICENSE=	GPLv3

MY_DEPENDS=	git:devel/git \
		rsync:net/rsync
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		cabal perl5
USE_LOCALE=	en_US.UTF-8
USE_PERL5=	build

USE_CABAL=	DAV-1.3.4 \
		HUnit-1.6.2.0 \
		IfElse-0.85 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		SafeSemaphore-0.10.1_1 \
		StateVar-1.2.2 \
		adjunctions-4.4.3 \
		aeson-2.2.3.0_4 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		attoparsec-aeson-2.2.2.0 \
		auto-update-0.2.6 \
		aws-0.25.2 \
		base-compat-0.14.1 \
		base-orphans-0.9.3 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bencode-0.6.1.1 \
		bifunctors-5.6.2_2 \
		bitvec-1.1.5.0_3 \
		blaze-builder-0.4.4.1 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		bloomfilter-2.0.1.3 \
		boring-0.2.2_1 \
		bsb-http-chunked-0.0.0.4_4 \
		byteable-0.1.1 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.12 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0_3 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		concurrent-output-1.10.21 \
		conduit-1.3.6.1 \
		conduit-extra-1.3.8_1 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		cookie-0.5.1 \
		crypto-api-0.13.3_1 \
		crypto-token-0.1.2 \
		cryptohash-md5-0.11.101.0_6 \
		cryptohash-sha1-0.11.101.0_6 \
		crypton-1.0.4 \
		crypton-connection-0.4.5 \
		crypton-socks-0.6.2 \
		crypton-x509-1.7.7 \
		crypton-x509-store-1.6.12_1 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.14 \
		data-default-0.8.0.1 \
		data-default-class-0.2.0.0 \
		data-fix-0.3.4_1 \
		dec-0.0.6_1 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		easy-file-0.2.5 \
		ech-config-0.0.1 \
		edit-distance-0.2.2.1_1 \
		entropy-0.4.1.11 \
		fast-logger-3.2.6 \
		feed-1.3.2.1_5 \
		file-embed-0.0.16.0 \
		file-io-0.1.5 \
		filepath-bytestring-1.5.2.0.3 \
		free-5.2_7 \
		generically-0.1.1_4 \
		generics-sop-0.5.1.4_2 \
		git-lfs-1.2.5 \
		half-0.3.3_1 \
		hashable-1.5.0.0_1 \
		hourglass-0.2.12_1 \
		hpke-0.0.0 \
		hsc2hs-0.68.10_4 \
		http-api-data-0.6.2 \
		http-client-0.7.19 \
		http-client-restricted-0.1.0 \
		http-client-tls-0.3.6.4_2 \
		http-conduit-2.3.9.1 \
		http-date-0.0.11 \
		http-media-0.8.1.1_2 \
		http-semantics-0.4.0 \
		http-types-0.12.4 \
		http2-5.4.0 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		invariant-0.6.4_1 \
		iproute-1.7.15 \
		kan-extensions-5.2.7 \
		lens-5.3.5_1 \
		lift-type-0.1.2.0 \
		lifted-base-0.2.3.12 \
		magic-1.1 \
		megaparsec-9.7.0 \
		memory-0.18.0_1 \
		microlens-0.5.0.0 \
		microlens-th-0.4.3.18 \
		mime-types-0.1.2.0 \
		mmorph-1.2.1_1 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.42 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.21.0 \
		network-3.2.8.0 \
		network-bsd-2.8.1.0_6 \
		network-byte-order-0.1.7 \
		network-control-0.1.7 \
		network-info-0.2.1 \
		network-multicast-0.3.2 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.19.0.0 \
		parallel-3.3.0.0 \
		parser-combinators-1.3.0_1 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.18.0.0 \
		persistent-sqlite-2.13.3.1 \
		persistent-template-2.12.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		profunctors-5.6.3 \
		psqueues-0.2.8.2 \
		random-1.3.1 \
		recv-0.1.1 \
		reflection-2.1.9_1 \
		regex-base-0.94.0.3 \
		regex-tdfa-1.3.2.5 \
		replace-megaparsec-1.5.0.1 \
		resource-pool-0.5.0.0 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		sandi-0.5_1 \
		scientific-0.3.8.0_2 \
		securemem-0.1.10 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		semigroups-0.20 \
		serialise-0.2.6.1_5 \
		servant-0.20.3.0_2 \
		servant-client-0.20.3.0_2 \
		servant-client-core-0.20.3.0_2 \
		servant-server-0.20.3.0_1 \
		shakespeare-2.2.0 \
		silently-1.2.5.4 \
		simple-sendfile-0.2.32 \
		singleton-bool-0.1.8_1 \
		socks-0.6.1 \
		some-1.0.6_2 \
		sop-core-0.5.0.2_5 \
		split-0.2.5 \
		splitmix-0.1.3.1 \
		stm-chans-3.0.0.9 \
		streaming-commons-0.2.3.1 \
		strict-0.5.1_1 \
		syb-0.7.3 \
		tagged-0.8.10 \
		tagsoup-0.14.8 \
		tasty-1.5.3_2 \
		tasty-hunit-0.10.2 \
		tasty-quickcheck-0.11.1_4 \
		tasty-rerun-1.1.20_2 \
		terminal-size-0.3.4_1 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		th-lift-0.8.6 \
		th-lift-instances-0.1.20 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		time-locale-compat-0.1.1.5 \
		time-manager-0.2.4 \
		tls-2.1.13 \
		tls-session-manager-0.0.8 \
		torrent-10000.1.3 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.13.0 \
		unbounded-delays-0.1.1.1 \
		unix-compat-0.7.4.1 \
		unix-time-0.4.17 \
		unliftio-0.2.25.1 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_1 \
		utf8-string-1.0.2 \
		uuid-1.3.16_3 \
		uuid-types-1.0.6_3 \
		vault-0.3.1.6 \
		vector-0.13.2.0_2 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_4 \
		void-0.7.4 \
		wai-3.2.4 \
		wai-app-static-3.1.9 \
		wai-extra-3.1.18 \
		wai-logger-2.5.0 \
		warp-3.4.11 \
		warp-tls-3.4.13 \
		witherable-0.5_1 \
		word8-0.1.3 \
		xml-conduit-1.10.1.0 \
		xml-hamlet-0.5.0.3 \
		xml-types-0.3.8 \
		zlib-0.7.1.1

CABAL_FLAGS=		production torrentparser magicmime \
			-benchmark -debuglocks

OPTIONS_DEFINE=		ASSISTANT
OPTIONS_DEFAULT=	ASSISTANT

ASSISTANT_DESC=		Enable assistant, webapp, and watch commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	alex-3.5.1.0 \
			clientsession-0.9.3.0 \
			cryptonite-0.30 \
			cryptonite-conduit-0.2.2_1 \
			css-text-0.1.3.0 \
			email-validate-2.3.2.21 \
			happy-2.1.7 \
			happy-lib-2.1.7 \
			hjsmin-0.2.1 \
			language-javascript-0.7.1.0 \
			libyaml-0.1.4 \
			libyaml-clib-0.2.5 \
			mountpoints-1.0.2 \
			setenv-0.1.1.3_1 \
			skein-1.0.9.4 \
			xss-sanitize-0.3.7.2_1 \
			yaml-0.11.11.2_2 \
			yesod-1.6.2.1 \
			yesod-core-1.6.28.1 \
			yesod-form-1.7.9 \
			yesod-persistent-1.6.0.8 \
			yesod-static-1.6.1.0

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-stage:
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex

.include <bsd.port.post.mk>
