# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sayonara
DISTVERSION=	1.5.1
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Small, clear, and fast Qt-based audio player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libmtp.so:multimedia/libmtp

USES=		cmake compiler:c++11-lib desktop-file-utils gnome pkgconfig \
		qt:5
USE_GNOME=	glib20
USE_GSTREAMER1=	flac libav mpg123 ogg opus vorbis
USE_QT=		dbus core gui network sql sql-sqlite3_run widgets xml \
		buildtools_build qmake_build linguisttools_build

USE_GITLAB=	yes
GL_ACCOUNT=	luciocarreras
GL_PROJECT=	${PORTNAME}-player
GL_COMMIT=	328203669eac9156db6f72356b47ebfbfee978ef  # 1.5.1-stable5

post-patch:
	@${REINPLACE_CMD} -e '/man1/s,share/,,' \
		${WRKSRC}/resources/CMakeLists.txt
	@${REINPLACE_CMD} -e '/DESTINATION/s,/usr/,,' \
		${WRKSRC}/src/Gui/Resources/Icons/CMakeLists.txt

.include <bsd.port.mk>
