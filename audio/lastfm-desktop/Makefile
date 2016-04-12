# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lastfm
PORTVERSION=	2.1.30
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://cdn.last.fm/client/Linux/
PKGNAMESUFFIX=	-desktop
DISTNAME=	Last.fm-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Official Last.fm desktop application suite

LICENSE=	GPLv3

LIB_DEPENDS=	liblastfm.so:audio/liblastfm \
		libavcodec.so:multimedia/ffmpeg \
		libgpod.so:audio/libgpod

USES=		pkgconfig qmake tar:bzip2 gmake
USE_QT4=	gui linguist_build moc_build network phonon \
		rcc_build uic_build webkit xml
LASTFM=		${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	${LASTFM}.sh

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${LASTFM}.sh ${STAGEDIR}${PREFIX}/bin/${LASTFM}
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/Last.fm\ Scrobbler ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/_bin/lib*.so* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/app/client/Last.fm\ Scrobbler.css \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
