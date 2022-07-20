PORTNAME=	sayonara
DISTVERSION=	1.7.0
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Small, clear, and fast Qt-based audio player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libmtp.so:multimedia/libmtp

USES=		cmake compiler:c++11-lib desktop-file-utils gnome gstreamer pkgconfig \
		qt:5 python shebangfix
USE_GNOME=	glib20
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis
USE_QT=		dbus core gui network sql sql-sqlite3_run svg widgets xml \
		buildtools_build qmake_build linguisttools_build

USE_GITLAB=	yes
GL_ACCOUNT=	luciocarreras
GL_PROJECT=	${PORTNAME}-player
GL_COMMIT=	5bbf1399332d5d59362ad03bf625f9132be72206 # 1.7.0-stable1

SHEBANG_FILES=	src/DBus/sayonara-ctl src/DBus/sayonara-query

post-patch:
	@${REINPLACE_CMD} \
		-e '/man1/s,share/,,' \
		-e '/DESTINATION/s,share/metainfo,share/appdata,' \
		${WRKSRC}/resources/CMakeLists.txt

.include <bsd.port.mk>
