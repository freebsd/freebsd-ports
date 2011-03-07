# New ports collection makefile for:	mediathek
# Date created:		2010-10-17
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mediathek
PORTVERSION=	2.5.0
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

INSTALLFILES=	Mediathek.jar
INSTALLDOCS=	make.txt releases.txt Kurzanleitung.pdf
INSTALLLIBS=	commons-compress-1.1.jar commons-lang-2.5.jar \
		jdom.jar rome-1.0.jar

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
		@${INSTALL_DATA} ${WRKSRC}/Anleitung/${i} ${DOCSDIR}/
.endfor
.endif
.for i in ${INSTALLLIBS}
	@${INSTALL_DATA} ${WRKSRC}/lib/${i} ${DATADIR}/lib/
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/mediathek ${PREFIX}/bin

.include <bsd.port.post.mk>
