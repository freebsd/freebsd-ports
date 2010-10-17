# New ports collection makefile for:	mediathek
# Date created:		2010-10-17
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mediathek
PORTVERSION=	2.2.1
CATEGORIES=	german java
MASTER_SITES=	SF/zdfmediathk/Mediathek/Mediathek%20${PORTVERSION}
DISTNAME=	Mediathek_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Filme der oeff. rechtlichen Sender herunterladen und ansehen

RUN_DEPENDS=	flvstreamer:${PORTSDIR}/multimedia/flvstreamer

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	mediathek

OPTIONS=	MPLAYER "mplayer zum Aufnehmen verwenden" on \
		VLC "VLC zum Abspielen verwenden" on

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_MPLAYER) && !defined(WITH_VLC)
	@${ECHO_MSG} "Es muss entweder mplayer oder VLC ausgewaehlt sein"
	@${FALSE}
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_VLC)
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} -q -d ${WRKSRC} ${_DISTDIR}/${EXTRACT_ONLY}

do-install:
	@cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} "${DATADIR}/{}" \;
	@cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	@${INSTALL_SCRIPT} ${WRKDIR}/mediathek ${PREFIX}/bin

.include <bsd.port.post.mk>
