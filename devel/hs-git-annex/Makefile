# Created by: frase@frase.id.au
# $FreeBSD$

PORTNAME=	git-annex
PORTVERSION=	3.20130124
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3
FILE_LICENSE=	COPYRIGHT

CABAL_SETUP=	Setup.hs

USE_CABAL=	async bloomfilter dataenc edit-distance hslogger HTTP IfElse \
		json lifted-base MissingH monad-control mtl network pcre-light \
		QuickCheck>=2.1 SafeSemaphore SHA text transformers-base \
		utf8-string

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

EXECUTABLE=	git-annex git-annex-shell
STANDALONE=	yes

OPTIONS_DEFINE=		S3 ASSISTANT INOTIFY WEBAPP PAIRING
OPTIONS_DEFAULT=	S3 ASSISTANT

S3_DESC=		S3 support
ASSISTANT_DESC=		'assistant' and 'watch' commands
INOTIFY_DESC=		File system notifications support
WEBAPP_DESC=		Web application (req. assistant)
PAIRING_DESC=		Enable pairing (req. web application)

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MS3}
CONFIGURE_ARGS+=	--flags="S3"
USE_CABAL+=		hS3
.else
CONFIGURE_ARGS+=	--flags="-S3"
.endif

.if ${PORT_OPTIONS:MASSISTANT}
CONFIGURE_ARGS+=	--flags="Assistant"
USE_CABAL+=		stm>=2.3
.else
CONFIGURE_ARGS+=	--flags="-Assistant"
.endif

.if ${PORT_OPTIONS:MINOTIFY}
CONFIGURE_ARGS+=	--flags="Inotify"
USE_CABAL+=		kqueue
.else
CONFIGURE_ARGS+=	--flags="-Inotify"
.endif

.if ${PORT_OPTIONS:MWEBAPP} && ${PORT_OPTIONS:MASSISTANT}
CONFIGURE_ARGS+=	--flags="Webapp"
USE_CABAL+=		yesod yesod-static case-insensitive http-types \
			transformers wai wai-logger warp blaze-builder \
			blaze-html crypto-api hamlet clientsession \
			yesod-default>=1.1.0 data-default
.else
CONFIGURE_ARGS+=	--flags="-Webapp"
.endif

.if ${PORT_OPTIONS:MWEBAPP} && ${PORT_OPTIONS:MPAIRING}
CONFIGURE_ARGS+=	--flags="Pairing"
USE_CABAL+=		network-multicast network-info
.else
CONFIGURE_ARGS+=	--flags="-Pairing"
.endif

# Disable all the other options
CONFIGURE_ARGS+=	--flags="-DNS -XMPP -Dbus"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
