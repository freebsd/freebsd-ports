# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	6.20170520
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3

USE_CABAL=	hslogger split IfElse QuickCheck SafeSemaphore bloomfilter \
		concurrent-output disk-free-space edit-distance esqueleto \
		feed magic network persistent-sqlite regex-tdfa sandi \
		torrent uuid

USES=		gmake perl5
USE_PERL5=	build

MAN1PAGES=	git-annex-add.1 git-annex-expire.1 git-annex-lookupkey.1 \
		git-annex-remotedaemon.1 git-annex-ungroup.1 \
		git-annex-addunused.1 git-annex-find.1 git-annex-map.1 \
		git-annex-repair.1 git-annex-uninit.1 git-annex-addurl.1 \
		git-annex-findref.1 git-annex-matchexpression.1 \
		git-annex-required.1 git-annex-unlock.1 git-annex-adjust.1 \
		git-annex-fix.1 git-annex-matching-options.1 \
		git-annex-resolvemerge.1 git-annex-untrust.1 \
		git-annex-assistant.1 git-annex-forget.1 git-annex-merge.1 \
		git-annex-rmurl.1 git-annex-unused.1 git-annex-calckey.1 \
		git-annex-fromkey.1 git-annex-metadata.1 git-annex-schedule.1 \
		git-annex-upgrade.1 git-annex-checkpresentkey.1 \
		git-annex-fsck.1 git-annex-migrate.1 git-annex-semitrust.1 \
		git-annex-vadd.1 git-annex-contentlocation.1 \
		git-annex-fuzztest.1 git-annex-mirror.1 git-annex-setkey.1 \
		git-annex-vcycle.1 git-annex-copy.1 git-annex-get.1 \
		git-annex-move.1 git-annex-setpresentkey.1 \
		git-annex-version.1 git-annex-dead.1 git-annex-group.1 \
		git-annex-multicast.1 git-annex-shell.1 git-annex-vfilter.1 \
		git-annex-describe.1 git-annex-groupwanted.1 \
		git-annex-numcopies.1 git-annex-smudge.1 git-annex-vicfg.1 \
		git-annex-diffdriver.1 git-annex-import.1 git-annex-p2p.1 \
		git-annex-status.1 git-annex-view.1 git-annex-direct.1 \
		git-annex-importfeed.1 git-annex-pre-commit.1 \
		git-annex-sync.1 git-annex-vpop.1 git-annex-drop.1 \
		git-annex-indirect.1 git-annex-preferred-content.1 \
		git-annex-test.1 git-annex-wanted.1 git-annex-dropkey.1 \
		git-annex-info.1 git-annex-proxy.1 git-annex-testremote.1 \
		git-annex-watch.1 git-annex-dropunused.1 git-annex-init.1 \
		git-annex-readpresentkey.1 git-annex-transferkey.1 \
		git-annex-webapp.1 git-annex-edit.1 git-annex-initremote.1 \
		git-annex-registerurl.1 git-annex-transferkeys.1 \
		git-annex-whereis.1 git-annex-enable-tor.1 git-annex-list.1 \
		git-annex-reinit.1 git-annex-trust.1 git-annex.1 \
		git-annex-enableremote.1 git-annex-lock.1 \
		git-annex-reinject.1 git-annex-unannex.1 \
		git-remote-tor-annex.1 git-annex-examinekey.1 git-annex-log.1 \
		git-annex-rekey.1 git-annex-undo.1

BUILD_DEPENDS+=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

RUN_DEPENDS+=	rsync:net/rsync \
		git:devel/git \
		gsha256sum:sysutils/coreutils

EXECUTABLE=	git-annex git-annex-shell git-remote-tor-annex
STANDALONE=	yes

FLAGS_DEFINE=	S3 ASSISTANT WEBDAV WEBAPP PAIRING PRODUCTION DBUS
FLAGS_DEFAULT=	S3 ASSISTANT WEBDAV WEBAPP PAIRING PRODUCTION

S3_DESC=		S3 support
S3_FLAG_ENABLE=		S3
S3_FLAG_CABAL=		conduit conduit-extra aws

WEBDAV_DESC=		WebDAV support
WEBDAV_FLAG_ENABLE=	WebDAV
WEBDAV_FLAG_CABAL=	DAV

ASSISTANT_DESC=		'assistant' and 'watch' commands
ASSISTANT_FLAG_ENABLE=	Assistant
ASSISTANT_FLAG_CABAL=	dns mountpoints hinotify 

WEBAPP_DESC=		Web application (requires assistant)
WEBAPP_FLAG_DEPENDS=	ASSISTANT
WEBAPP_FLAG_ENABLE=	Webapp
WEBAPP_FLAG_CABAL=	yesod yesod-static yesod-form yesod-core path-pieces \
			warp warp-tls wai wai-extra blaze-builder \
			clientsession shakespeare

PAIRING_DESC=		Enable pairing (requires web application)
PAIRING_FLAG_DEPENDS=	WEBAPP
PAIRING_FLAG_ENABLE=	Pairing
PAIRING_FLAG_CABAL=	network-multicast network-info

PRODUCTION_DESC=	Production build
PRODUCTION_FLAG_ENABLE=	Production

DBUS_DESC=		Dbus support
DBUS_FLAG_ENABLE=	Dbus
DBUS_FLAG_CABAL=	dbus fdo-notify

FLAGS_ENABLE=		ConcurrentOutput TorrentParser MagicMime
FLAGS_DISABLE=		Benchmark TestSuite Android AndroidSplice

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
