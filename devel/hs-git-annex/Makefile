PORTNAME=	git-annex
PORTVERSION=	10.20231227
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git
WWW=		https://git-annex.branchable.com/

LICENSE=	GPLv3

BROKEN_aarch64=	compiler crashes

BUILD_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		ghc-9.4.8:lang/ghc94

RUN_DEPENDS=	rsync:net/rsync \
		git:devel/git

USES=		cabal perl5

USE_PERL5=	build
USE_LOCALE=	en_US.UTF-8
USE_CABAL=	DAV-1.3.4 \
		IfElse-0.85 \
		OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		SafeSemaphore-0.10.1_1 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_2 \
		aeson-2.1.2.1_3 \
		ansi-terminal-1.0.2 \
		ansi-terminal-types-0.11.5_1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1_1 \
		async-2.2.5 \
		attoparsec-0.14.4_5 \
		attoparsec-aeson-2.1.0.0 \
		auto-update-0.1.6 \
		aws-0.24.1 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.1 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bencode-0.6.1.1 \
		bifunctors-5.6.1_2 \
		bitvec-1.1.5.0 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.1.2_4 \
		blaze-markup-0.8.3.0_1 \
		bloomfilter-2.0.1.2 \
		byteable-0.1.1 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_3 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		concurrent-output-1.10.20 \
		conduit-1.3.5 \
		conduit-extra-1.3.6 \
		contravariant-1.5.5 \
		cookie-0.4.6 \
		crypto-api-0.13.3_1 \
		cryptohash-md5-0.11.101.0_3 \
		cryptohash-sha1-0.11.101.0_3 \
		crypton-0.34 \
		crypton-connection-0.3.1 \
		crypton-x509-1.7.6_1 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.12 \
		cryptonite-0.30 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_5 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		easy-file-0.2.5 \
		edit-distance-0.2.2.1_1 \
		entropy-0.4.1.10_1 \
		fast-logger-3.2.2 \
		feed-1.3.2.1_2 \
		file-embed-0.0.15.0 \
		filepath-bytestring-1.4.2.1.13 \
		foldable1-classes-compat-0.1_4 \
		free-5.2_3 \
		generically-0.1.1_2 \
		git-lfs-1.2.1 \
		hashable-1.4.3.0_1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.10_1 \
		http-api-data-0.6_1 \
		http-client-0.7.16 \
		http-client-restricted-0.1.0 \
		http-client-tls-0.3.6.3 \
		http-conduit-2.3.8.3 \
		http-types-0.12.4 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		invariant-0.6.2_1 \
		iproute-1.7.12 \
		kan-extensions-5.2.5_2 \
		lens-5.2.3_2 \
		lift-type-0.1.1.1 \
		lifted-base-0.2.3.12 \
		magic-1.1 \
		memory-0.18.0 \
		microlens-0.4.13.1_1 \
		microlens-th-0.4.3.14 \
		mime-types-0.1.2.0 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.40 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		network-3.1.4.0_1 \
		network-bsd-2.8.1.0_5 \
		network-info-0.2.1 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.18.1.0 \
		parallel-3.2.2.0_7 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.14.6.0 \
		persistent-sqlite-2.13.3.0 \
		persistent-template-2.12.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.8.0.0_1 \
		profunctors-5.6.2_3 \
		random-1.2.1.1_1 \
		reflection-2.1.7_1 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_2 \
		resource-pool-0.4.0.0 \
		resourcet-1.3.0 \
		safe-0.3.20 \
		safe-exceptions-0.1.7.4_1 \
		sandi-0.5_1 \
		scientific-0.3.7.0_7 \
		securemem-0.1.10 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		semigroups-0.20 \
		shakespeare-2.1.0.1 \
		silently-1.2.5.3 \
		socks-0.6.1 \
		split-0.2.5 \
		splitmix-0.1.0.5 \
		stm-chans-3.0.0.9 \
		streaming-commons-0.2.2.6_1 \
		strict-0.5_1 \
		syb-0.7.2.4 \
		tagged-0.8.8 \
		tagsoup-0.14.8 \
		tasty-1.5_1 \
		tasty-hunit-0.10.1 \
		tasty-quickcheck-0.10.3_1 \
		tasty-rerun-1.1.19_2 \
		terminal-size-0.3.4 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.5.0.0 \
		th-compat-0.1.4_3 \
		th-lift-0.8.4 \
		th-lift-instances-0.1.20 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		time-locale-compat-0.1.1.5 \
		tls-1.9.0 \
		torrent-10000.1.3 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.1 \
		unix-compat-0.7.1 \
		unix-time-0.4.11 \
		unliftio-0.2.25.0 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		utf8-string-1.0.2 \
		uuid-1.3.15_3 \
		uuid-types-1.0.5.1 \
		vault-0.3.1.5_5 \
		vector-0.13.1.0 \
		vector-algorithms-0.9.0.1_3 \
		vector-stream-0.1.0.1 \
		void-0.7.3 \
		witherable-0.4.2_4 \
		xml-conduit-1.9.1.3 \
		xml-hamlet-0.5.0.2 \
		xml-types-0.3.8 \
		zlib-0.6.3.0_4

OPTIONS_DEFINE=		ASSISTANT WEBAPP PAIRING DBUS
OPTIONS_DEFAULT=	ASSISTANT WEBAPP PAIRING DBUS

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	mountpoints-1.0.2

WEBAPP_DESC=		Web application (implies ASSISTANT and PAIRING)
WEBAPP_IMPLIES=		ASSISTANT PAIRING
WEBAPP_CABAL_FLAGS=	webapp
WEBAPP_USE_CABAL=	HUnit-1.6.2.0 \
			alex-3.2.7.4 \
			bsb-http-chunked-0.0.0.4_3 \
			cipher-aes-0.2.11 \
			clientsession-0.9.1.2 \
			clock-0.8.3 \
			cprng-aes-0.6.1 \
			crypto-cipher-types-0.0.9 \
			crypto-random-0.0.9_1 \
			cryptonite-conduit-0.2.2_1 \
			css-text-0.1.3.0 \
			email-validate-2.3.2.18 \
			happy-1.20.1.1 \
			hjsmin-0.2.1 \
			http-date-0.0.11 \
			http2-5.0.1 \
			language-javascript-0.7.1.0 \
			libyaml-0.1.2_1 \
			mountpoints-1.0.2 \
			network-byte-order-0.1.7 \
			network-control-0.0.2 \
			network-multicast-0.3.2 \
			psqueues-0.2.7.3 \
			recv-0.1.0 \
			setenv-0.1.1.3_1 \
			simple-sendfile-0.2.31 \
			skein-1.0.9.4 \
			time-manager-0.0.1 \
			tls-session-manager-0.0.4 \
			wai-3.2.3 \
			wai-app-static-3.1.7.4 \
			wai-extra-3.1.13.0_1 \
			wai-logger-2.4.0 \
			warp-3.3.31 \
			warp-tls-3.4.3 \
			word8-0.1.3 \
			xss-sanitize-0.3.7.2 \
			yaml-0.11.11.0 \
			yesod-1.6.2.1 \
			yesod-core-1.6.24.2 \
			yesod-form-1.7.4 \
			yesod-persistent-1.6.0.8 \
			yesod-static-1.6.1.0

PAIRING_DESC=		Enable pairing
PAIRING_CABAL_FLAGS=	pairing
PAIRING_USE_CABAL=	network-multicast-0.3.2

DBUS_DESC=		D-Bus support
DBUS_CABAL_FLAGS=	dbus
DBUS_USE_CABAL=		dbus-1.3.2 \
			fdo-notify-0.3.1

CABAL_FLAGS=		production torrentparser magicmime \
			-benchmark -debuglocks

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-stage:
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex

.include <bsd.port.post.mk>
