PORTNAME=	git-annex
DISTVERSION=	10.20240831
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git
WWW=		https://git-annex.branchable.com/

LICENSE=	GPLv3

BROKEN_aarch64=	compiler crashes

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
		OneTuple-0.4.2 \
		QuickCheck-2.15.0.1 \
		SafeSemaphore-0.10.1_1 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_2 \
		aeson-2.2.3.0_2 \
		ansi-terminal-1.1.1 \
		ansi-terminal-types-1.1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1.1 \
		async-2.2.5_2 \
		attoparsec-0.14.4_5 \
		attoparsec-aeson-2.2.2.0 \
		auto-update-0.2.1 \
		aws-0.24.2 \
		base-compat-0.13.1 \
		base-orphans-0.9.2 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bencode-0.6.1.1 \
		bifunctors-5.6.2 \
		bitvec-1.1.5.0_1 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		bloomfilter-2.0.1.2 \
		boring-0.2.2 \
		bsb-http-chunked-0.0.0.4_4 \
		byteable-0.1.1 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.10 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0_1 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		concurrent-output-1.10.21 \
		conduit-1.3.6 \
		conduit-extra-1.3.6 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		cookie-0.5.0 \
		crypto-api-0.13.3_1 \
		crypto-token-0.1.1 \
		cryptohash-md5-0.11.101.0_5 \
		cryptohash-sha1-0.11.101.0_5 \
		crypton-1.0.0 \
		crypton-connection-0.4.1 \
		crypton-x509-1.7.7 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.12 \
		cryptonite-0.30 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.4 \
		dec-0.0.6 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		easy-file-0.2.5 \
		edit-distance-0.2.2.1_1 \
		entropy-0.4.1.10_2 \
		fast-logger-3.2.3 \
		feed-1.3.2.1_4 \
		file-embed-0.0.16.0 \
		filepath-bytestring-1.4.100.3.2 \
		free-5.2_5 \
		generically-0.1.1_3 \
		git-lfs-1.2.2 \
		half-0.3.1_2 \
		hashable-1.5.0.0 \
		hourglass-0.2.12_1 \
		hsc2hs-0.68.10_2 \
		http-api-data-0.6.1_1 \
		http-client-0.7.17 \
		http-client-restricted-0.1.0 \
		http-client-tls-0.3.6.3 \
		http-conduit-2.3.9 \
		http-date-0.0.11 \
		http-media-0.8.1.1_2 \
		http-semantics-0.2.1 \
		http-types-0.12.4 \
		http2-5.3.4 \
		indexed-traversable-0.1.4 \
		indexed-traversable-instances-0.1.2 \
		integer-conversion-0.1.1 \
		integer-logarithms-1.0.3.1_6 \
		invariant-0.6.3 \
		iproute-1.7.14 \
		kan-extensions-5.2.6 \
		lens-5.3.2_2 \
		lift-type-0.1.2.0 \
		lifted-base-0.2.3.12 \
		magic-1.1 \
		memory-0.18.0 \
		microlens-0.4.13.1_1 \
		microlens-th-0.4.3.15 \
		mime-types-0.1.2.0 \
		mmorph-1.2.0_3 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.40 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.17.0 \
		network-3.2.2.0 \
		network-bsd-2.8.1.0_6 \
		network-byte-order-0.1.7 \
		network-control-0.1.3 \
		network-info-0.2.1 \
		network-multicast-0.3.2 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.18.1.0 \
		os-string-2.0.6 \
		parallel-3.2.2.0_8 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.14.6.3 \
		persistent-sqlite-2.13.3.0 \
		persistent-template-2.12.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_1 \
		profunctors-5.6.2_3 \
		psqueues-0.2.8.0_1 \
		random-1.2.1.2 \
		recv-0.1.0 \
		reflection-2.1.8 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_3 \
		resource-pool-0.4.0.0 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		sandi-0.5_1 \
		scientific-0.3.8.0_1 \
		securemem-0.1.10 \
		semialign-1.3.1_1 \
		semigroupoids-6.0.1_1 \
		semigroups-0.20 \
		serialise-0.2.6.1_3 \
		servant-0.20.2 \
		servant-client-0.20.2 \
		servant-client-core-0.20.2 \
		servant-server-0.20.2 \
		shakespeare-2.1.0.1 \
		silently-1.2.5.3 \
		simple-sendfile-0.2.32 \
		singleton-bool-0.1.8 \
		socks-0.6.1 \
		some-1.0.6_1 \
		sop-core-0.5.0.2_4 \
		split-0.2.5 \
		splitmix-0.1.0.5_1 \
		stm-chans-3.0.0.9 \
		streaming-commons-0.2.2.6_1 \
		strict-0.5.1_1 \
		syb-0.7.2.4 \
		tagged-0.8.8_1 \
		tagsoup-0.14.8 \
		tasty-1.5_2 \
		tasty-hunit-0.10.2 \
		tasty-quickcheck-0.11 \
		tasty-rerun-1.1.19_3 \
		terminal-size-0.3.4_1 \
		text-iso8601-0.1.1_1 \
		text-short-0.1.6_2 \
		th-abstraction-0.7.0.0 \
		th-compat-0.1.5_2 \
		th-lift-0.8.4_2 \
		th-lift-instances-0.1.20 \
		these-1.2.1_1 \
		time-compat-1.9.7_2 \
		time-locale-compat-0.1.1.5 \
		time-manager-0.1.0 \
		tls-2.1.0 \
		tls-session-manager-0.0.6 \
		torrent-10000.1.3 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.12.0 \
		unbounded-delays-0.1.1.1 \
		unix-compat-0.7.2 \
		unix-time-0.4.15 \
		unliftio-0.2.25.0 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_3 \
		utf8-string-1.0.2 \
		uuid-1.3.16_1 \
		uuid-types-1.0.6_1 \
		vault-0.3.1.5_8 \
		vector-0.13.1.0_1 \
		vector-algorithms-0.9.0.2_1 \
		vector-stream-0.1.0.1_1 \
		void-0.7.3 \
		wai-3.2.4 \
		wai-app-static-3.1.9 \
		wai-extra-3.1.15 \
		wai-logger-2.4.1 \
		warp-3.4.1_1 \
		warp-tls-3.4.6 \
		witherable-0.5_1 \
		word8-0.1.3 \
		xml-conduit-1.9.1.3 \
		xml-hamlet-0.5.0.2 \
		xml-types-0.3.8 \
		zlib-0.7.1.0_1

CABAL_FLAGS=		assistant production torrentparser magicmime \
			-benchmark -debuglocks

OPTIONS_DEFINE=		ASSISTANT
OPTIONS_DEFAULT=	ASSISTANT

ASSISTANT_DESC=		Enable assistant, webapp, and watch commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	alex-3.5.1.0 \
			clientsession-0.9.3.0 \
			cryptonite-conduit-0.2.2_1 \
			css-text-0.1.3.0 \
			email-validate-2.3.2.20 \
			happy-1.20.1.1 \
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
			yesod-core-1.6.26.0 \
			yesod-form-1.7.6 \
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
