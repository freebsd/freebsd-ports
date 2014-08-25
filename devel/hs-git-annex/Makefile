# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	5.20140817
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

USE_CABAL=	MissingH hslogger utf8-string network>=2.0 mtl>=2 HTTP \
		extensible-exceptions exceptions>=0.5 dataenc SHA json \
		monad-control MonadCatchIO-transformers IfElse text \
		QuickCheck>=2.1 bloomfilter edit-distance SafeSemaphore \
		uuid random dlist unix-compat aeson data-default \
		case-insensitive

USES=		gmake perl5
USE_PERL5=	build

MAN1PAGES=	git-annex.1 git-annex-shell.1

BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git \
		gsha256sum:${PORTSDIR}/sysutils/coreutils

RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git \
		gsha256sum:${PORTSDIR}/sysutils/coreutils

EXECUTABLE=	git-annex git-annex-shell
STANDALONE=	yes

FLAGS_DEFINE=	S3 WEBDAV INOTIFY ASSISTANT WEBAPP WEBAPP_SECURE PAIRING \
		XMPP DNS PRODUCTION TDFA FEED QUVI TAHOE CRYPTOHASH EKG
FLAGS_DEFAULT=	S3 WEBDAV INOTIFY ASSISTANT WEBAPP WEBAPP_SECURE PAIRING \
		XMPP DNS PRODUCTION TDFA FEED QUVI TAHOE CRYPTOHASH

S3_DESC=		S3 support
S3_FLAG_ENABLE=		S3
S3_FLAG_CABAL=		hS3

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_FLAG_ENABLE=	Assistant
ASSISTANT_FLAG_CABAL=	async stm>=2.3

INOTIFY_DESC=		File system notifications support
INOTIFY_FLAG_ENABLE=	Inotify
INOTIFY_FLAG_CABAL=	kqueue

WEBAPP_DESC=		Web application (requires assistant)
WEBAPP_FLAG_DEPENDS=	ASSISTANT
WEBAPP_FLAG_ENABLE=	Webapp
WEBAPP_FLAG_CABAL=	yesod yesod-static yesod-static yesod-form yesod-core \
			case-insensitive http-types wai wai-logger warp \
			blaze-builder crypto-api shakespeare clientsession \
			data-default warp-tls path-pieces

WEBAPP_SECURE_DESC=		Secure webapp (requires webbapp)
WEBAPP_SECURE_FLAG_DEPENDS=	WEBAPP
WEBAPP_SECURE_FLAG_ENABLE=	Webapp-secure
WEBAPP_SECURE_FLAG_CABAL=	warp-tls>=1.4 securemem byteable

PAIRING_DESC=		Enable pairing (requires web application)
PAIRING_FLAG_DEPENDS=	WEBAPP
PAIRING_FLAG_ENABLE=	Pairing
PAIRING_FLAG_CABAL=	network-multicast network-info

XMPP_DESC=		Enable notifications using XMPP (requires assistant)
XMPP_FLAG_DEPENDS=	ASSISTANT
XMPP_FLAG_ENABLE=	XMPP
XMPP_FLAG_CABAL=	gnutls>=0.1.4 network-protocol-xmpp xml-types

DNS_DESC=		Use the DNS library for lookups (requires XMPP)
DNS_FLAG_DEPENDS=	ASSISTANT XMPP
DNS_FLAG_ENABLE=	DNS
DNS_FLAG_CABAL=		dns

PRODUCTION_DESC=	Production build
PRODUCTION_FLAG_ENABLE=	Production

TDFA_DESC=		Use regex-tdfa for wildcards
TDFA_FLAG_ENABLE=	TDFA
TDFA_FLAG_CABAL=	regex-tdfa

WEBDAV_DESC=		WebDAV support
WEBDAV_FLAG_ENABLE=	WebDAV
WEBDAV_FLAG_CABAL=	DAV>=0.3 http-conduit xml-conduit http-types

FEED_DESC=		Podcast feed support
FEED_FLAG_ENABLE=	Feed
FEED_FLAG_CABAL=	feed

QUVI_DESC=		quvi to download videos
QUVI_FLAG_ENABLE=	Quvi
QUVI_FLAG_CABAL=	aeson

CRYPTOHASH_DESC=	cryptohash for checksumming
CRYPTOHASH_FLAG_ENABLE=	CryptoHash
CRYPTOHASH_FLAG_CABAL=	cryptohash>=0.10.0

EKG_DESC=		EKG for run-time monitoring
EKG_FLAG_ENABLE=	EKG
EKG_FLAG_CABAL=		ekg

TAHOE_DESC=		Enable the tahoe special remote
TAHOE_FLAG_ENABLE=	Tahoe
TAHOE_FLAG_CABAL=	aeson

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
