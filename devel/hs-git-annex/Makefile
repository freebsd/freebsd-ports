# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	7.20190129
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

BUILD_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils \
		happy:devel/hs-happy \
		hs-network>=2.6:net/hs-network

RUN_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

USES=		cabal perl5

USE_PERL5=	build

USE_CABAL=	IfElse-0.85 QuickCheck-2.12.6.1_1 SafeSemaphore-0.10.1_1 \
		StateVar-1.1.1.1 adjunctions-4.4_2 aeson-1.4.2.0_1 \
		aeson-compat-0.3.9 alex-3.2.4 ansi-terminal-0.9 ansi-wl-pprint-0.6.8.2_1 \
		appar-0.1.7 asn1-encoding-0.9.5 asn1-parse-0.9.4 asn1-types-0.3.2 \
		async-2.2.1_1 attoparsec-0.13.2.2 attoparsec-iso8601-1.0.1.0 \
		auto-update-0.1.4 base-compat-0.10.5 base-orphans-0.8 \
		basement-0.0.10_1 bencode-0.6.0.0 bifunctors-5.5.3 \
		blaze-builder-0.4.1.0 blaze-html-0.9.1.1 blaze-markup-0.8.2.2 \
		bloomfilter-2.0.1.0 bsb-http-chunked-0.0.0.4 byteable-0.1.1 \
		byteorder-1.0.4 cabal-doctest-1.0.6_2 call-stack-0.1.0 \
		case-insensitive-1.2.0.11 cereal-0.5.8.0 cipher-aes-0.2.11 \
		clientsession-0.9.1.2 clock-0.7.2 colour-2.3.4 comonad-5.0.4 \
		concurrent-output-1.10.9 conduit-1.3.1 conduit-extra-1.3.0 \
		connection-0.2.8 contravariant-1.5 cookie-0.4.4 cprng-aes-0.6.1 \
		crypto-api-0.13.3 crypto-cipher-types-0.0.9 crypto-random-0.0.9 \
		cryptohash-md5-0.11.100.1_3 cryptohash-sha1-0.11.100.1_3 \
		cryptonite-0.25 cryptonite-conduit-0.2.2 css-text-0.1.3.0 \
		data-default-0.7.1.1 data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 disk-free-space-0.1.0.1_3 \
		distributive-0.6 dlist-0.8.0.5 easy-file-0.2.2 edit-distance-0.2.2.1_1 \
		email-validate-2.3.2.10 entropy-0.4.1.4 erf-2.0.0.0 \
		exceptions-0.10.0_2 fast-logger-2.4.13 feed-1.0.1.0 \
		file-embed-0.0.11 fingertree-0.1.4.2 free-5.1 happy-1.19.9_3 \
		hashable-1.2.7.0_1 hjsmin-0.2.0.2 \
		hourglass-0.2.12 hsc2hs-0.68.4 hslogger-1.2.12 http-api-data-0.4 \
		http-client-0.6.1 http-client-tls-0.3.5.3 http-conduit-2.3.5 \
		http-date-0.0.8 http-types-0.12.2 http2-1.6.4 \
		integer-logarithms-1.0.2.2 invariant-0.5.1_1 iproute-1.7.7 \
		kan-extensions-5.2 language-javascript-0.6.0.11 lens-4.17 \
		libyaml-0.1.1.0 lifted-base-0.2.3.12 magic-1.1 memory-0.14.18_1 \
		microlens-0.4.10 microlens-th-0.4.2.3 mime-types-0.1.0.9 \
		monad-control-1.0.2.3 monad-logger-0.3.30 monad-loops-0.4.3 \
		mono-traversable-1.0.11.0 network-byte-order-0.0.0.0 \
		network-info-0.2.0.10 network-uri-2.6.1.0_1 \
		old-time-1.1.0.3_2 optparse-applicative-0.14.3.0 \
		parallel-3.2.2.0 path-pieces-0.2.1_1 pem-0.2.4 persistent-2.9.1_1 \
		persistent-sqlite-2.9.2 persistent-template-2.6.0 \
		primitive-0.6.4.0_1 profunctors-5.3 psqueues-0.2.7.1 random-1.1_1 \
		reducers-3.12.3 reflection-2.1.4 regex-base-0.93.2 \
		regex-tdfa-1.2.3.1 resource-pool-0.2.3.2 resourcet-1.2.2 \
		rio-0.1.8.0 safe-0.3.17 sandi-0.5 scientific-0.3.6.2 \
		securemem-0.1.10 semigroupoids-5.3.2 semigroups-0.18.5 \
		setenv-0.1.1.3_1 shakespeare-2.0.20 silently-1.2.5 \
		simple-sendfile-0.2.28 skein-1.0.9.4 socks-0.5.6_1 split-0.2.3.3_1 \
		stm-chans-3.0.0.4_1 streaming-commons-0.2.1.0 syb-0.7 \
		tagged-0.8.6 tagsoup-0.14.7 tasty-1.2.1 tasty-hunit-0.10.0.1 \
		tasty-quickcheck-0.10_1 tasty-rerun-1.1.14 terminal-size-0.3.2.1 \
		tf-random-0.5 th-abstraction-0.2.10.0 time-locale-compat-0.1.1.5 \
		tls-1.4.1 tls-session-manager-0.0.0.2 torrent-10000.1.1 \
		transformers-base-0.4.5.2 transformers-compat-0.6.2 \
		typed-process-0.2.4.0 unbounded-delays-0.1.1.0 \
		unix-compat-0.5.1 unix-time-0.4.5 unliftio-0.2.10 \
		unliftio-core-0.1.2.0_1 unordered-containers-0.2.10.0 \
		utf8-string-1.0.1.1_3 uuid-1.3.13_2 uuid-types-1.0.3_1 vault-0.3.1.2 \
		vector-0.12.0.2 vector-algorithms-0.8.0.1 void-0.7.2 wai-3.2.2 \
		wai-app-static-3.1.6.2 wai-logger-2.3.4 wai-extra-3.0.25 warp-3.2.26 \
		wcwidth-0.0.2 word8-0.1.3 \
		x509-1.7.5 x509-store-1.6.7 x509-system-1.6.6 \
		x509-validation-1.6.11 xml-conduit-1.8.0.1 xml-hamlet-0.5.0 \
		xml-types-0.3.6 xss-sanitize-0.3.6 yaml-0.11.0.0 yesod-core-1.6.12 \
		yesod-persistent-1.6.0.1 zlib-0.6.2

OPTIONS_DEFINE=		S3 ASSISTANT WEBDAV WEBAPP PAIRING DBUS
OPTIONS_DEFAULT=	S3 ASSISTANT WEBDAV WEBAPP PAIRING

S3_DESC=		S3 support
S3_CABAL_FLAGS=		s3
S3_USE_CABAL=		aws-0.21 base16-bytestring-0.1.1.6 base64-bytestring-1.0.0.2 old-locale-1.0.0.7_2

WEBDAV_DESC=		WebDAV support
WEBDAV_CABAL_FLAGS=	webdav
WEBDAV_USE_CABAL=	DAV-1.3.3

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	mountpoints-1.0.2

WEBAPP_DESC=		Web application (requires ASSISTANT)
WEBAPP_IMPLIES=		ASSISTANT
WEBAPP_CABAL_FLAGS=	webapp
WEBAPP_USE_CABAL=	yesod-1.6.0 yesod-form-1.6.4 \
			yesod-static-1.6.0.1 \
			warp-tls-3.2.4.3

PAIRING_DESC=		Enable pairing (requires WEBAPP)
PAIRING_IMPLIES=	WEBAPP
PAIRING_CABAL_FLAGS=	pairing
PAIRING_USE_CABAL=	network-multicast-0.2.0

DBUS_DESC=		D-Bus support
DBUS_CABAL_FLAGS=	dbus
DBUS_USE_CABAL=		dbus-1.2.3 fdo-notify-0.3.1 th-lift-0.7.11

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
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${LN} -sf git-annex ${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex

.include <bsd.port.mk>
