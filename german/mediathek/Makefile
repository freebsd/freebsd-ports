# New ports collection makefile for:	mediathek
# Date created:		2010-10-17
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mediathek
PORTVERSION=	3.0.0
CATEGORIES=	german java
MASTER_SITES=	SF/zdfmediathk/Mediathek/Mediathek%20${PORTVERSION}
DISTNAME=	MediathekView_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Filme der oeff. rechtlichen Sender herunterladen und ansehen

RUN_DEPENDS=	flvstreamer:${PORTSDIR}/multimedia/flvstreamer

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	mediathek

INSTALLFILES=	MediathekView.jar
INSTALLDOCS=	Anleitung.pdf
INSTALLLIBS=	commons-compress-1.4.jar commons-lang3-3.1.jar \
		jdom-2.0.0.jar

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MPLAYER VLC

VLC_DESC=		VLC support

OPTIONS_DEFAULT=	VLC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} -q -d ${WRKSRC} ${DISTDIR}/${EXTRACT_ONLY}

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/lib
.for i in ${INSTALLFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}/
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${INSTALLDOCS}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
.for i in ${INSTALLLIBS}
	@${INSTALL_DATA} ${WRKSRC}/lib/${i} ${DATADIR}/lib/
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/mediathek ${PREFIX}/bin

.include <bsd.port.mk>
