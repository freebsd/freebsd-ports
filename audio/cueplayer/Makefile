# New ports collection makefile for:	cueplayer
# Date created:		2010-01-17
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	cueplayer
PORTVERSION=	0.21
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	CUE player

USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build network
USE_GSTREAMER=	yes

DESKTOP_ENTRIES="Cueplayer" "Lightweight media player based on Qt and Gstreamer" \
		"${DATADIR}/knotify.png" "${PORTNAME}" \
		"AudioVideo;Audio;Video;" ${FALSE}

post-patch:
	${REINPLACE_CMD} -e 's,images/,share/${PORTNAME}/,g' \
		${WRKSRC}/*.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}

.include <bsd.port.mk>
