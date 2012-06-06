# New ports collection makefile for:	quimup
# Date created:				2011-02-08
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	quimup
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=musicpd/Quimup/${PORTVERSION}
DISTNAME=	${PORTNAME}_${DISTVERSION}_source

MAINTAINER=	cm@therek.net
COMMENT=	QT4 Client for MPD (the Music Player Daemon)

LIB_DEPENDS=	mpdclient.2:${PORTSDIR}/audio/libmpdclient

USE_QT4=	corelib gui network \
		qmake_build moc_build rcc_build uic_build
QMAKE_ARGS=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png
PLIST_DIRS=	share/icons/hicolor/32x32/apps \
		share/icons/hicolor/32x32 \
		share/icons/hicolor/48x48/apps \
		share/icons/hicolor/48x48 \
		share/icons/hicolor/64x64/apps \
		share/icons/hicolor/64x64 \
		share/icons/hicolor \
		share/icons

.include  <bsd.port.pre.mk>

do-configure:
	${REINPLACE_CMD} -e 's|/usr/lib/libmpdclient.so|${LOCALBASE}/lib/libmpdclient.so|' \
		${WRKSRC}/${PORTNAME}.pro
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/icons/hicolor/32x32/apps
	${MKDIR} ${PREFIX}/share/icons/hicolor/48x48/apps
	${MKDIR} ${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/Icons/${PORTNAME}32.png \
		${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/Icons/${PORTNAME}48.png \
		${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/Icons/${PORTNAME}64.png \
		${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png

.include <bsd.port.post.mk>
