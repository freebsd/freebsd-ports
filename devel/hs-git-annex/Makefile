# Created by: frase@frase.id.au

PORTNAME=	git-annex
PORTVERSION=	10.20220525
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

BUILD_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

RUN_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

USES=		cabal perl5

USE_PERL5=	build
USE_LOCALE=	en_US.UTF-8
USE_CABAL=	DAV-1.3.4 \
		IfElse-0.85 \
		OneTuple-0.3.1_2 \
		QuickCheck-2.14.2 \
		SafeSemaphore-0.10.1_1 \
		StateVar-1.2.2 \
		adjunctions-4.4.1 \
		aeson-2.0.3.0 \
		ansi-terminal-0.11.3 \
		ansi-wl-pprint-0.6.9_3 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_2 \
		async-2.2.4_1 \
		attoparsec-0.14.4_1 \
		attoparsec-iso8601-1.0.2.1 \
		auto-update-0.1.6 \
		aws-0.22_3 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1_2 \
		base-orphans-0.8.6 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.14 \
		bencode-0.6.1.1 \
		bifunctors-5.5.12 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_2 \
		bloomfilter-2.0.1.0_2 \
		byteable-0.1.1 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_1 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.2_1 \
		clock-0.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		concurrent-output-1.10.16 \
		conduit-1.3.4.2 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.5 \
		crypto-api-0.13.3_1 \
		cryptohash-md5-0.11.101.0 \
		cryptohash-sha1-0.11.101.0 \
		cryptonite-0.30 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_2 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		easy-file-0.2.2 \
		edit-distance-0.2.2.1_1 \
		entropy-0.4.1.7 \
		fast-logger-3.1.1 \
		feed-1.3.2.1 \
		file-embed-0.0.15.0 \
		filepath-bytestring-1.4.2.1.10 \
		free-5.1.8 \
		git-lfs-1.2.0 \
		hashable-1.4.0.2 \
		hourglass-0.2.12 \
		hsc2hs-0.68.8 \
		http-api-data-0.4.3_6 \
		http-client-0.7.11_1 \
		http-client-restricted-0.0.5 \
		http-client-tls-0.3.6.1 \
		http-conduit-2.3.8 \
		http-types-0.12.3 \
		indexed-traversable-0.1.2_1 \
		indexed-traversable-instances-0.1.1 \
		integer-logarithms-1.0.3.1_2 \
		invariant-0.5.6 \
		iproute-1.7.12 \
		kan-extensions-5.2.4 \
		lens-5.1.1 \
		lift-type-0.1.0.1 \
		lifted-base-0.2.3.12 \
		magic-1.1 \
		memory-0.17.0 \
		microlens-0.4.13.0 \
		microlens-th-0.4.3.10 \
		mime-types-0.1.0.9 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.36_2 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		network-3.1.2.7 \
		network-bsd-2.8.1.0_4 \
		network-info-0.2.1 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optparse-applicative-0.17.0.0 \
		parallel-3.2.2.0_4 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.14.0.1 \
		persistent-sqlite-2.13.1.0 \
		persistent-template-2.12.0.0 \
		primitive-0.7.4.0 \
		profunctors-5.6.2_2 \
		random-1.2.1.1 \
		reflection-2.1.6_1 \
		regex-base-0.94.0.2_1 \
		regex-tdfa-1.3.1.2_1 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.5 \
		safe-0.3.19 \
		sandi-0.5_1 \
		scientific-0.3.7.0_2 \
		securemem-0.1.10 \
		semialign-1.2.0.1_1 \
		semigroupoids-5.3.7 \
		semigroups-0.20 \
		shakespeare-2.0.29 \
		silently-1.2.5.2 \
		socks-0.6.1 \
		split-0.2.3.4_2 \
		splitmix-0.1.0.4 \
		stm-chans-3.0.0.6 \
		streaming-commons-0.2.2.4 \
		strict-0.4.0.1_4 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_2 \
		tagsoup-0.14.8 \
		tasty-1.4.2.3 \
		tasty-hunit-0.10.0.3 \
		tasty-quickcheck-0.10.2 \
		tasty-rerun-1.1.18_3 \
		terminal-size-0.3.3 \
		text-short-0.1.5 \
		th-abstraction-0.4.3.0 \
		th-compat-0.1.3_1 \
		th-lift-0.8.2_1 \
		th-lift-instances-0.1.19 \
		these-1.1.1.1_5 \
		time-compat-1.9.6.1_3 \
		time-locale-compat-0.1.1.5 \
		tls-1.5.7 \
		torrent-10000.1.1 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.1_1 \
		typed-process-0.2.8.0_1 \
		unbounded-delays-0.1.1.1 \
		unix-compat-0.6 \
		unix-time-0.4.7 \
		unliftio-0.2.22.0 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.19.1 \
		utf8-string-1.0.2 \
		uuid-1.3.15_1 \
		uuid-types-1.0.5_2 \
		vault-0.3.1.5_1 \
		vector-0.12.3.1_2 \
		vector-algorithms-0.8.0.4_1 \
		void-0.7.3 \
		wcwidth-0.0.2 \
		witherable-0.4.2_2 \
		x509-1.7.6 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		xml-conduit-1.9.1.1_1 \
		xml-hamlet-0.5.0.2 \
		xml-types-0.3.8 \
		zlib-0.6.3.0

OPTIONS_DEFINE=		ASSISTANT WEBAPP PAIRING DBUS
OPTIONS_DEFAULT=	ASSISTANT WEBAPP PAIRING DBUS

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	mountpoints-1.0.2

WEBAPP_DESC=		Web application (implies ASSISTANT and PAIRING)
WEBAPP_IMPLIES=		ASSISTANT PAIRING
WEBAPP_CABAL_FLAGS=	webapp
WEBAPP_USE_CABAL=	HUnit-1.6.2.0 \
			alex-3.2.7.1 \
			bsb-http-chunked-0.0.0.4_3 \
			cipher-aes-0.2.11 \
			clientsession-0.9.1.2 \
			cprng-aes-0.6.1 \
			crypto-cipher-types-0.0.9 \
			crypto-random-0.0.9_1 \
			cryptonite-conduit-0.2.2_1 \
			css-text-0.1.3.0 \
			email-validate-2.3.2.16 \
			happy-1.20.0_1 \
			hjsmin-0.2.0.4_2 \
			http-date-0.0.11 \
			http2-3.0.3 \
			language-javascript-0.7.1.0 \
			libyaml-0.1.2 \
			mountpoints-1.0.2 \
			network-byte-order-0.1.6_1 \
			network-multicast-0.3.2 \
			psqueues-0.2.7.3 \
			setenv-0.1.1.3_1 \
			simple-sendfile-0.2.30 \
			skein-1.0.9.4 \
			time-manager-0.0.0 \
			tls-session-manager-0.0.4 \
			wai-3.2.3 \
			wai-app-static-3.1.7.4 \
			wai-extra-3.1.12.1 \
			wai-logger-2.4.0 \
			warp-3.3.21 \
			warp-tls-3.3.2 \
			word8-0.1.3 \
			xss-sanitize-0.3.7_1 \
			yaml-0.11.8.0 \
			yesod-1.6.2 \
			yesod-core-1.6.23.1 \
			yesod-form-1.7.0 \
			yesod-persistent-1.6.0.8 \
			yesod-static-1.6.1.0

PAIRING_DESC=		Enable pairing
PAIRING_CABAL_FLAGS=	pairing
PAIRING_USE_CABAL=	network-multicast-0.3.2

DBUS_DESC=		D-Bus support
DBUS_CABAL_FLAGS=	dbus
DBUS_USE_CABAL=		dbus-1.2.24 \
			fdo-notify-0.3.1

CABAL_FLAGS=		production torrentparser magicmime \
			-benchmark -debuglocks

EXECUTABLES=	git-annex

MAN1PAGES=	git-annex-add git-annex-expire git-annex-lookupkey \
		git-annex-remotedaemon git-annex-ungroup \
		git-annex-addunused git-annex-find git-annex-map \
		git-annex-repair git-annex-uninit git-annex-addurl \
		git-annex-findref git-annex-matchexpression \
		git-annex-required git-annex-unlock git-annex-adjust \
		git-annex-fix git-annex-matching-options \
		git-annex-resolvemerge git-annex-untrust \
		git-annex-assistant git-annex-forget git-annex-merge \
		git-annex-rmurl git-annex-unused git-annex-calckey \
		git-annex-fromkey git-annex-metadata git-annex-schedule \
		git-annex-upgrade git-annex-checkpresentkey \
		git-annex-fsck git-annex-migrate git-annex-semitrust \
		git-annex-vadd git-annex-contentlocation \
		git-annex-fuzztest git-annex-mirror git-annex-setkey \
		git-annex-vcycle git-annex-copy git-annex-get \
		git-annex-move git-annex-setpresentkey \
		git-annex-version git-annex-dead git-annex-group \
		git-annex-multicast git-annex-shell git-annex-vfilter \
		git-annex-describe git-annex-groupwanted \
		git-annex-numcopies git-annex-smudge git-annex-vicfg \
		git-annex-diffdriver git-annex-import git-annex-p2p \
		git-annex-status git-annex-view git-annex-direct \
		git-annex-importfeed git-annex-pre-commit \
		git-annex-sync git-annex-vpop git-annex-drop \
		git-annex-indirect git-annex-preferred-content \
		git-annex-test git-annex-wanted git-annex-dropkey \
		git-annex-info git-annex-proxy git-annex-testremote \
		git-annex-watch git-annex-dropunused git-annex-init \
		git-annex-readpresentkey git-annex-transferkey \
		git-annex-webapp git-annex-edit git-annex-initremote \
		git-annex-registerurl git-annex-transferkeys \
		git-annex-whereis git-annex-enable-tor git-annex-list \
		git-annex-reinit git-annex-trust git-annex \
		git-annex-enableremote git-annex-lock \
		git-annex-reinject git-annex-unannex \
		git-remote-tor-annex git-annex-examinekey git-annex-log \
		git-annex-rekey git-annex-undo

post-build:
.for man in ${MAN1PAGES}
	${WRKSRC}/Build/mdwn2man ${man} 1 ${WRKSRC}/doc/${man}.mdwn > ${WRKSRC}/doc/${man}.1
.endfor

post-install:
.for man in ${MAN1PAGES}
	${INSTALL_MAN} ${WRKSRC}/doc/${man}.1 ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor

post-stage:
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}/git-annex-shell
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}/git-remote-tor-annex
	${CP} ${STAGEDIR}${PREFIX}/bin/git-annex ${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${CP} ${STAGEDIR}${PREFIX}/bin/git-annex ${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex
	${REINPLACE_CMD} 's|${PREFIX}/${CABAL_LIBEXEC}/git-annex|${PREFIX}/${CABAL_LIBEXEC}/git-annex-shell|' \
		${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${REINPLACE_CMD} 's|${PREFIX}/${CABAL_LIBEXEC}/git-annex|${PREFIX}/${CABAL_LIBEXEC}/git-remote-tor-annex|' \
		${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex

.include <bsd.port.mk>
