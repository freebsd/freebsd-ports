# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	5.20150727
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

USE_CABAL=	optparse-applicative>=0.10 cryptohash>=0.11.0 exceptions>=0.6 \
		QuickCheck>=2.1 stm>=2.3 mtl>=2 data-default case-insensitive \
		uuid random dlist unix-compat SafeSemaphore async IfElse \
		MissingH hslogger monad-logger utf8-string text sandi json \
		monad-control bloomfilter edit-distance resourcet aws>=0.9.2 \
		http-conduit http-types network>=2.6 network-uri>=2.6

USES=		gmake perl5
USE_PERL5=	build

MAN1PAGES=	git-annex.1 git-annex-shell.1

BUILD_DEPENDS+=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

RUN_DEPENDS+=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

EXECUTABLE=	git-annex git-annex-shell
STANDALONE=	yes

FLAGS_DEFINE=	S3 WEBDAV INOTIFY ASSISTANT WEBAPP WEBAPP_SECURE PAIRING \
		XMPP DNS PRODUCTION TDFA FEED QUVI TAHOE DESKTOPNOTIFY \
		TORRENTPARSER EKG DATABASE
FLAGS_DEFAULT=	S3 WEBDAV INOTIFY ASSISTANT WEBAPP WEBAPP_SECURE PAIRING \
		XMPP DNS PRODUCTION TDFA FEED QUVI TAHOE DATABASE

S3_DESC=		S3 support
S3_FLAG_ENABLE=		S3
S3_FLAG_CABAL=		hS3

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_FLAG_ENABLE=	Assistant

INOTIFY_DESC=		File system notifications support
INOTIFY_FLAG_ENABLE=	Inotify
INOTIFY_FLAG_CABAL=	hinotify

WEBAPP_DESC=		Web application (requires assistant)
WEBAPP_FLAG_DEPENDS=	ASSISTANT
WEBAPP_FLAG_ENABLE=	Webapp
WEBAPP_FLAG_CABAL=	yesod>=1.2.6 yesod-static>=1.2.4 yesod-form>=1.3.15 \
			yesod-core>=1.2.19 path-pieces>=0.1.4 warp>=3.0.05 \
			warp-tls wai wai-extra blaze-builder crypto-api \
			clientsession aeson shakespeare>=2.0.0

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

TAHOE_DESC=		Tahoe special remote
TAHOE_FLAG_ENABLE=	Tahoe
TAHOE_FLAG_CABAL=	aeson

DESKTOPNOTIFY_DESC=		Desktop environment notifications
DESKTOPNOTIFY_FLAG_ENABLE=	DesktopNotify

TORRENTPARSER_DESC=		Use haskell torrent library to parse torrent files
TORRENTPARSER_FLAG_ENABLE=	TorrentParser
TORRENTPARSER_FLAG_CABAL=	torrent>=10000.0.0

EKG_DESC=		EKG for run-time monitoring
EKG_FLAG_ENABLE=	EKG
EKG_FLAG_CABAL=		ekg

DATABASE_DESC=		Build with persistent for database use
DATABASE_FLAG_ENABLE=	Database
DATABASE_FLAG_CABAL=	esqueleto persistent-sqlite persistent \
			persistent-template

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
