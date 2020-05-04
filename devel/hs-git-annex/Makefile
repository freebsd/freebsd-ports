# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	8.20200330
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
USE_CABAL=	IfElse-0.85 \
		QuickCheck-2.14 \
		SafeSemaphore-0.10.1_1 \
		StateVar-1.2 \
		aeson-1.4.7.1_1 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		attoparsec-iso8601-1.0.1.0_1 \
		auto-update-0.1.6 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		base64-bytestring-1.0.0.3 \
		basement-0.0.11_2 \
		bencode-0.6.1.1 \
		bifunctors-5.5.7 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.2 \
		blaze-markup-0.8.2.4 \
		bloomfilter-2.0.1.0 \
		byteable-0.1.1 \
		cabal-doctest-1.0.8_1 \
		call-stack-0.2.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8 \
		colour-2.3.5 \
		comonad-5.0.6 \
		concurrent-output-1.10.11 \
		conduit-1.3.2 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		contravariant-1.5.2 \
		cookie-0.4.5 \
		crypto-api-0.13.3_1 \
		cryptohash-md5-0.11.100.1_4 \
		cryptohash-sha1-0.11.100.1_5 \
		cryptonite-0.26 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.1 \
		dlist-0.8.0.8 \
		easy-file-0.2.2 \
		edit-distance-0.2.2.1_1 \
		entropy-0.4.1.5 \
		exceptions-0.10.4_1 \
		fast-logger-3.0.1 \
		feed-1.3.0.1 \
		filepath-bytestring-1.4.2.1.6 \
		free-5.1.3 \
		hashable-1.3.0.0_1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.6 \
		hslogger-1.3.1.0 \
		http-api-data-0.4.1.1_1 \
		http-client-0.6.4.1 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.7.3 \
		http-types-0.12.3 \
		integer-logarithms-1.0.3_2 \
		lifted-base-0.2.3.12 \
		magic-1.1 \
		memory-0.15.0_1 \
		microlens-0.4.11.2 \
		microlens-th-0.4.3.4 \
		mime-types-0.1.0.9 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.32 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.1 \
		network-3.1.1.1 \
		network-bsd-2.8.1.0_3 \
		network-info-0.2.0.10_1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optparse-applicative-0.15.1.0_1 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.10.5.2 \
		persistent-sqlite-2.10.6.2 \
		persistent-template-2.8.2.3 \
		primitive-0.7.0.1 \
		profunctors-5.5.2 \
		random-1.1_1 \
		regex-base-0.94.0.0_1 \
		regex-tdfa-1.3.1.0_1 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.3 \
		safe-0.3.18_1 \
		sandi-0.5_1 \
		scientific-0.3.6.2 \
		securemem-0.1.10 \
		semigroupoids-5.3.4 \
		silently-1.2.5.1 \
		socks-0.6.1 \
		split-0.2.3.4 \
		splitmix-0.0.4 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.1.2 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		tagsoup-0.14.8 \
		tasty-1.2.3 \
		tasty-hunit-0.10.0.2 \
		tasty-quickcheck-0.10.1.1 \
		tasty-rerun-1.1.17 \
		terminal-size-0.3.2.1 \
		th-abstraction-0.3.2.0 \
		th-lift-0.8.1 \
		th-lift-instances-0.1.14 \
		time-compat-1.9.3 \
		time-locale-compat-0.1.1.5 \
		tls-1.5.4 \
		torrent-10000.1.1 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		typed-process-0.2.6.0 \
		unbounded-delays-0.1.1.0 \
		unix-compat-0.5.2_1 \
		unix-time-0.4.7 \
		unliftio-0.2.12.1 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		uuid-1.3.13_3 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		wcwidth-0.0.2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		xml-conduit-1.9.0.0 \
		xml-types-0.3.6 \
		zlib-0.6.2.1_1

OPTIONS_DEFINE=		S3 ASSISTANT WEBDAV WEBAPP PAIRING DBUS
OPTIONS_DEFAULT=	S3 ASSISTANT WEBDAV WEBAPP PAIRING DBUS

S3_DESC=		S3 support
S3_CABAL_FLAGS=		s3
S3_USE_CABAL=		aws-0.22 base16-bytestring-0.1.1.6

WEBDAV_DESC=		WebDAV support
WEBDAV_CABAL_FLAGS=	webdav
WEBDAV_USE_CABAL=	DAV-1.3.4 \
			adjunctions-4.4_2 \
			invariant-0.5.3_1 \
			kan-extensions-5.2 \
			lens-4.19.1 \
			parallel-3.2.2.0_2 \
			reflection-2.1.5 \
			semigroups-0.19.1 \
			shakespeare-2.0.24 \
			void-0.7.3 \
			xml-hamlet-0.5.0.1

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	mountpoints-1.0.2

WEBAPP_DESC=		Web application (implies ASSISTANT, PAIRING and WEBDAV)
WEBAPP_IMPLIES=		ASSISTANT PAIRING WEBDAV
WEBAPP_CABAL_FLAGS=	webapp
WEBAPP_USE_CABAL=	adjunctions-4.4_2 \
			alex-3.2.5 \
			appar-0.1.8 \
			bsb-http-chunked-0.0.0.4_2 \
			byteorder-1.0.4 \
			cipher-aes-0.2.11 \
			clientsession-0.9.1.2 \
			cprng-aes-0.6.1 \
			crypto-cipher-types-0.0.9 \
			crypto-random-0.0.9_1 \
			cryptonite-conduit-0.2.2_1 \
			css-text-0.1.3.0 \
			email-validate-2.3.2.12 \
			file-embed-0.0.11.2 \
			happy-1.19.12 \
			hjsmin-0.2.0.4 \
			http-date-0.0.8 \
			http2-2.0.4 \
			invariant-0.5.3_1 \
			iproute-1.7.9 \
			language-javascript-0.7.1.0 \
			libyaml-0.1.2 \
			network-byte-order-0.1.4.0 \
			parallel-3.2.2.0_2 \
			psqueues-0.2.7.2_1 \
			setenv-0.1.1.3_1 \
			simple-sendfile-0.2.30 \
			skein-1.0.9.4 \
			time-manager-0.0.0 \
			tls-session-manager-0.0.4 \
			vault-0.3.1.3 \
			wai-3.2.2.1 \
			wai-app-static-3.1.7.1_1 \
			wai-extra-3.0.29.1 \
			wai-logger-2.3.6 \
			warp-3.3.9 \
			warp-tls-3.2.11 \
			word8-0.1.3 \
			xml-hamlet-0.5.0.1 \
			xss-sanitize-0.3.6 \
			yaml-0.11.3.0 \
			yesod-1.6.0.1 \
			yesod-core-1.6.18 \
			yesod-form-1.6.7 \
			yesod-persistent-1.6.0.4 \
			yesod-static-1.6.0.1 \

PAIRING_DESC=		Enable pairing
PAIRING_CABAL_FLAGS=	pairing
PAIRING_USE_CABAL=	network-multicast-0.3.2

DBUS_DESC=		D-Bus support
DBUS_CABAL_FLAGS=	Dbus
DBUS_USE_CABAL=		adjunctions-4.4_2 \
			dbus-1.2.13 \
			fdo-notify-0.3.1 \
			invariant-0.5.3_1 \
			kan-extensions-5.2 \
			lens-4.19.1 \
			parallel-3.2.2.0_2 \
			reflection-2.1.5 \
			semigroups-0.19.1 \
			void-0.7.3

CABAL_FLAGS=		torrentparser magicmime \
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
