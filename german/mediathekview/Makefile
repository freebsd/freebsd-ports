# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mediathekview
PORTVERSION=	13.0.6
CATEGORIES=	german java
MASTER_SITES=	https://download.mediathekview.de/stabil/
DISTNAME=	MediathekView-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Filme der oeff. rechtlichen Sender herunterladen und ansehen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/Copyright/_mediathekView-LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/openjdk8/bin/javafxpackager:java/openjfx8-devel \
		flvstreamer:multimedia/flvstreamer

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+
SUB_FILES=	${PORTNAME}

NO_ARCH=	yes

INSTALLFILES=	MediathekView.jar MediathekView.ico
INSTALLDOCS=	Kurzanleitung.pdf Instructions.pdf

OPTIONS_DEFINE=		DOCS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MPLAYER MPV VLC

VLC_DESC=		VLC support
MPV_DESC=		MPV support

OPTIONS_DEFAULT=	MPV

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv
VLC_RUN_DEPENDS=	vlc:multimedia/vlc

DESKTOP_ENTRIES="MediathekView" \
		"Filme der oeff. rechtlichen Sender herunterladen und ansehen" \
		"${DATADIR}/MediathekView.ico" \
		"${PORTNAME}" \
		"Video;AudioVideo;Java;" \
		false

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
.for i in ${INSTALLFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${INSTALLDOCS}
		${INSTALL_DATA} ${WRKSRC}/Anleitung/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib/)
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
