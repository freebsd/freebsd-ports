PORTNAME=	radish-play
DISTVERSION=	g20250621
CATEGORIES=	japanese audio

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Japanese Internet radio player
WWW=		https://github.com/jg1uaa/radish-play

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl \
		jq:textproc/jq \
		xmllint:textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	jg1uaa
GH_TAGNAME=	2e4f02c
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFAULT=	MPV
OPTIONS_SINGLE=		PLAYER
OPTIONS_SINGLE_PLAYER=	FFPLAY MPV
FFPLAY_DESC=		Use ffplay (via ffmpeg, implies the SDL option)
MPV_DESC=		Use mpv as media player

FFPLAY_RUN_DEPENDS=	ffplay:multimedia/ffmpeg
FFPLAY_EXTRA_PATCHES=	${PATCHDIR}/ffplay-patch-radish-play.sh
MPV_RUN_DEPENDS=	mpv:multimedia/mpv
MPV_EXTRA_PATCHES=	${PATCHDIR}/mpv-patch-radish-play.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
