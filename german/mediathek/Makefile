# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mediathek
PORTVERSION=	11
CATEGORIES=	german java
MASTER_SITES=	SF/zdfmediathk/Mediathek/Mediathek%20${PORTVERSION}
DISTNAME=	MediathekView_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Filme der oeff. rechtlichen Sender herunterladen und ansehen

RUN_DEPENDS=	flvstreamer:multimedia/flvstreamer

NO_BUILD=	yes
USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.7+
SUB_FILES=	mediathek

INSTALLFILES=	MediathekView.jar MediathekView.ico
INSTALLDOCS=	Kurzanleitung.pdf Instructions.pdf

OPTIONS_DEFINE=		DOCS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MPLAYER VLC

VLC_DESC=		VLC support

OPTIONS_DEFAULT=	VLC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	vlc:multimedia/vlc
.endif

DESKTOP_ENTRIES="MediathekView" \
		"Filme der oeff. rechtlichen Sender herunterladen und ansehen" \
		"${DATADIR}/MediathekView.ico" \
		"mediathek" \
		"Video;AudioVideo;Java;" \
		false

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} -q -d ${WRKSRC} ${DISTDIR}/${EXTRACT_ONLY}

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
	${INSTALL_SCRIPT} ${WRKDIR}/mediathek ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
