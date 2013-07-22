# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lastfm
PORTVERSION=	2.1.30
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cdn.last.fm/client/Linux/
PKGNAMESUFFIX=	-desktop
DISTNAME=	Last.fm-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Official Last.fm desktop application suite

LICENSE=	GPLv3

LIB_DEPENDS=	lastfm:${PORTSDIR}/audio/liblastfm \
		avcodec1:${PORTSDIR}/multimedia/ffmpeg1 \
		gpod:${PORTSDIR}/audio/libgpod

USE_BZIP2=	yes
USE_QT4=	gui linguist_build moc_build network phonon qmake_build \
		rcc_build uic_build webkit xml
USE_LDCONFIG=	yes
LASTFM=		${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	${LASTFM}.sh

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${LASTFM}.sh ${PREFIX}/bin/${LASTFM}
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/Last.fm\ Scrobbler ${DATADIR}/
	${INSTALL_LIB} ${WRKSRC}/_bin/lib*.so* ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/app/client/Last.fm\ Scrobbler.css \
		${DATADIR}/

.include <bsd.port.mk>
