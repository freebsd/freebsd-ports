# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sayonara
DISTVERSIONPREFIX=	player-
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-git1-20171231
CATEGORIES=	audio
MASTER_SITES=	http://www.sayonara-player.com/sw/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Small, clear, and fast Qt-based audio player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libtag.so:audio/taglib \
		libmtp.so:multimedia/libmtp

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		pkgconfig
USE_GNOME=	glib20
USE_GSTREAMER1=	flac libav mpg123 ogg opus vorbis
USE_QT5=	dbus core gui network sql sql-sqlite3_run widgets xml \
		buildtools_build qmake_build linguisttools_build

WRKSRC=		${WRKDIR}/${PORTNAME}-player

post-patch:
	@${REINPLACE_CMD} -e '/man1/s,share/,,' \
		${WRKSRC}/resources/CMakeLists.txt
	@${REINPLACE_CMD} -e '/DESTINATION/s,/usr/,,' \
		${WRKSRC}/src/GUI/Resources/Icons/CMakeLists.txt

.include <bsd.port.mk>
