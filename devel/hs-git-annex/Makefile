# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	7.20190626
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

BUILD_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils \
		hs-network==2.8.0.1:net/hs-network

RUN_DEPENDS=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

USES=		cabal perl5

USE_PERL5=	build
USE_LOCALE=	en_US.UTF-8
USE_CABAL=                                                \
    IfElse-0.85                                           \
    Glob-0.10.0_1                                         \
    Only-0.1                                              \
    QuickCheck-2.13.2                                     \
    SafeSemaphore-0.10.1                                  \
    StateVar-1.2                                          \
    abstract-deque-0.3                                    \
    abstract-par-0.3.3                                    \
    aeson-1.4.4.0                                         \
    ansi-terminal-0.9.1                                   \
    ansi-wl-pprint-0.6.9                                  \
    asn1-encoding-0.9.5                                   \
    asn1-parse-0.9.4                                      \
    asn1-types-0.3.3                                      \
    async-2.2.2                                           \
    attoparsec-0.13.2.2                                   \
    attoparsec-iso8601-1.0.1.0                            \
    auto-update-0.1.5                                     \
    base-compat-0.10.5                                    \
    base-orphans-0.8.1                                    \
    base64-bytestring-1.0.0.2                             \
    basement-0.0.10                                       \
    bencode-0.6.0.0                                       \
    bifunctors-5.5.4                                      \
    blaze-builder-0.4.1.0                                 \
    blaze-html-0.9.1.1                                    \
    blaze-markup-0.8.2.2                                  \
    bloomfilter-2.0.1.0                                   \
    byteable-0.1.1                                        \
    cabal-doctest-1.0.6_2                                 \
    call-stack-0.1.0                                      \
    case-insensitive-1.2.1.0                              \
    cereal-0.5.8.1                                        \
    clock-0.8                                             \
    colour-2.3.5                                          \
    comonad-5.0.5                                         \
    concurrent-output-1.10.10                             \
    conduit-1.3.1.1                                       \
    conduit-extra-1.3.3                                   \
    connection-0.3.0                                      \
    contravariant-1.5.2                                   \
    cookie-0.4.4                                          \
    crypto-api-0.13.3                                     \
    cryptohash-md5-0.11.100.1_3                           \
    cryptohash-sha1-0.11.100.1_3                          \
    cryptonite-0.26                                       \
    data-default-0.7.1.1                                  \
    data-default-class-0.1.2.0                            \
    data-default-instances-containers-0.0.1               \
    data-default-instances-dlist-0.0.1                    \
    data-default-instances-old-locale-0.0.1               \
    dense-linear-algebra-0.1.0.0                          \
    disk-free-space-0.1.0.1                               \
    distributive-0.6                                      \
    dlist-0.8.0.6                                         \
    easy-file-0.2.2                                       \
    edit-distance-0.2.2.1                                 \
    entropy-0.4.1.4                                       \
    exceptions-0.10.2                                     \
    fast-logger-2.4.16                                    \
    feed-1.1.0.0                                          \
    fingertree-0.1.4.2                                    \
    free-5.1.1                                            \
    hashable-1.2.7.0_1                                    \
    hsc2hs-0.68.4                                         \
    hourglass-0.2.12                                      \
    hslogger-1.3.0.0                                      \
    http-api-data-0.4.1                                   \
    http-client-0.6.4                                     \
    http-client-tls-0.3.5.3                               \
    http-conduit-2.3.7.1                                  \
    http-types-0.12.3                                     \
    integer-logarithms-1.0.3                              \
    js-flot-0.8.3                                         \
    js-jquery-3.3.1                                       \
    lifted-base-0.2.3.12                                  \
    magic-1.1                                             \
    math-functions-0.3.1.0                                \
    memory-0.14.18                                        \
    microlens-0.4.11.1                                    \
    microlens-th-0.4.3.1                                  \
    microstache-1.0.1.1_4                                 \
    mime-types-0.1.0.9                                    \
    monad-control-1.0.2.3                                 \
    monad-logger-0.3.30                                   \
    monad-loops-0.4.3                                     \
    monad-par-0.3.4.8                                     \
    monad-par-extras-0.3.3                                \
    mono-traversable-1.0.11.0                             \
    mwc-random-0.14.0.0                                   \
    network-bsd-2.8.0.0                                   \
    network-info-0.2.0.10_1                               \
    network-uri-2.6.1.0                                   \
    old-locale-1.0.0.7_2                                  \
    old-time-1.1.0.3_2                                    \
    optparse-applicative-0.14.3.0                         \
    parallel-3.2.2.0                                      \
    path-pieces-0.2.1                                     \
    pcre-light-0.4.0.4                                    \
    pem-0.2.4                                             \
    persistent-2.10.0                                     \
    persistent-sqlite-2.10.1                              \
    persistent-template-2.7.1                             \
    primitive-0.7.0.0                                     \
    profunctors-5.4                                       \
    random-1.1                                            \
    reducers-3.12.3_1                                     \
    regex-base-0.93.2                                     \
    regex-posix-0.95.2                                    \
    regex-tdfa-1.2.3.2                                    \
    resource-pool-0.2.3.2                                 \
    resourcet-1.2.2                                       \
    safe-0.3.17                                           \
    sandi-0.5                                             \
    scientific-0.3.6.2                                    \
    securemem-0.1.10                                      \
    semigroupoids-5.3.2_1                                 \
    semigroups-0.19                                       \
    silently-1.2.5                                        \
    socks-0.6.0                                           \
    split-0.2.3.3_1                                       \
    splitmix-0.0.2                                        \
    statistics-0.15.0.0                                   \
    stm-chans-3.0.0.4_1                                   \
    streaming-commons-0.2.1.1                             \
    syb-0.7.1                                             \
    tagged-0.8.6                                          \
    tagsoup-0.14.8                                        \
    tasty-1.2.3                                           \
    tasty-hunit-0.10.0.2                                  \
    tasty-quickcheck-0.10.1                               \
    tasty-rerun-1.1.14                                    \
    terminal-size-0.3.2.1                                 \
    text-short-0.1.2_2                                    \
    th-abstraction-0.3.1.0                                \
    time-compat-1.9.2.2                                   \
    time-locale-compat-0.1.1.5                            \
    tls-1.5.0                                             \
    torrent-10000.1.1                                     \
    transformers-base-0.4.5.2                             \
    transformers-compat-0.6.5                             \
    typed-process-0.2.5.0                                 \
    unbounded-delays-0.1.1.0                              \
    unix-compat-0.5.1                                     \
    unix-time-0.4.7                                       \
    unliftio-core-0.1.2.0_2                               \
    unordered-containers-0.2.10.0_1                       \
    utf8-string-1.0.1.1_3                                 \
    uuid-1.3.13_2                                         \
    uuid-types-1.0.3_2                                    \
    vector-0.12.0.3                                       \
    vector-algorithms-0.8.0.1_2                           \
    vector-binary-instances-0.2.5.1                       \
    vector-th-unbox-0.2.1.6                               \
    wcwidth-0.0.2                                         \
    x509-1.7.5                                            \
    x509-store-1.6.7                                      \
    x509-system-1.6.6                                     \
    x509-validation-1.6.11                                \
    xml-conduit-1.8.0.1                                   \
    xml-types-0.3.6                                       \
    zlib-0.6.2

OPTIONS_DEFINE=		S3 ASSISTANT WEBDAV WEBAPP PAIRING DBUS
OPTIONS_DEFAULT=	S3 ASSISTANT WEBDAV WEBAPP PAIRING

S3_DESC=		S3 support
S3_CABAL_FLAGS=		s3
S3_USE_CABAL=		aws-0.21.1 base16-bytestring-0.1.1.6

WEBDAV_DESC=		WebDAV support
WEBDAV_CABAL_FLAGS=	webdav
WEBDAV_USE_CABAL=	DAV-1.3.3 xml-hamlet-0.5.0 lens-4.17.1_1 reflection-2.1.4_1 kan-extensions-5.2 invariant-0.5.3 adjunctions-4.4_2 void-0.7.3 shakespeare-2.0.20

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_CABAL_FLAGS=	assistant
ASSISTANT_USE_CABAL=	mountpoints-1.0.2

WEBAPP_DESC=		Web application (implies ASSISTANT, PAIRING and WEBDAV)
WEBAPP_IMPLIES=		ASSISTANT PAIRING WEBDAV
WEBAPP_BUILD_DEPENDS=	happy:devel/hs-happy \
			alex:devel/hs-alex
WEBAPP_CABAL_FLAGS=	webapp
WEBAPP_USE_CABAL=	yesod-static-1.6.0.1 yesod-core-1.6.14 word8-0.1.3 \
			warp-3.3.0 wai-3.2.2.1 vault-0.3.1.2 time-manager-0.0.0 \
			simple-sendfile-0.2.28_2 iproute-1.7.7 byteorder-1.0.4 \
			appar-0.1.8 http2-2.0.3 psqueues-0.2.7.2 \
			network-byte-order-0.1.1.0 http-date-0.0.8 \
			bsb-http-chunked-0.0.0.4 wai-logger-2.3.5 wai-extra-3.0.26.1 \
			void-0.7.3 unliftio-0.2.11 shakespeare-2.0.20 rio-0.1.10.0 \
			clientsession-0.9.1.2 skein-1.0.9.4 setenv-0.1.1.3_1 \
			crypto-random-0.0.9_1 cprng-aes-0.6.1 cipher-aes-0.2.11 \
			crypto-cipher-types-0.0.9 wai-app-static-3.1.6.3_3 file-embed-0.0.11 \
			hjsmin-0.2.0.2 language-javascript-0.6.0.13 happy-1.19.11 \
			alex-3.2.4 css-text-0.1.3.0 cryptonite-conduit-0.2.2_1 \
			yesod-form-1.6.5 yesod-persistent-1.6.0.2 xss-sanitize-0.3.6 \
			email-validate-2.3.2.11 yesod-1.6.0 yaml-0.11.1.0 \
			libyaml-0.1.1.0 warp-tls-3.2.7 tls-session-manager-0.0.2.1 \
			network-multicast-0.3.2

PAIRING_DESC=		Enable pairing
#PAIRING_IMPLIES=	WEBAPP
PAIRING_CABAL_FLAGS=	pairing
PAIRING_USE_CABAL=	network-multicast-0.3.2

DBUS_DESC=		D-Bus support
DBUS_CABAL_FLAGS=	Dbus
DBUS_USE_CABAL=		dbus-1.2.7 fdo-notify-0.3.1 th-lift-0.8.0.1 lens-4.17.1_1 reflection-2.1.4_1 kan-extensions-5.2 invariant-0.5.3 adjunctions-4.4_2 void-0.7.3 xml-conduit-1.8.0.1

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
