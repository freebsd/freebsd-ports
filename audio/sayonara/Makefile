PORTNAME=	sayonara
DISTVERSION=	1.10.0
DISTVERSIONSUFFIX=	-stable1
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Small, clear, and fast Qt-based audio player
WWW=		https://www.sayonara-player.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libmtp.so:multimedia/libmtp

USES=		cmake compiler:c++11-lib desktop-file-utils gnome gstreamer pkgconfig \
		qt:5 python shebangfix
USE_GNOME=	glib20
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis
USE_QT=		dbus core gui network sql sql-sqlite3:run svg widgets xml \
		buildtools:build qmake:build linguisttools:build \
		testlib:build

USE_GITLAB=	yes
GL_ACCOUNT=	luciocarreras
GL_PROJECT=	${PORTNAME}-player

SHEBANG_FILES=	src/DBus/sayonara-ctl src/DBus/sayonara-query

post-patch:
	@${REINPLACE_CMD} \
		-e '/DESTINATION/s,share/metainfo,share/appdata,' \
		${WRKSRC}/resources/CMakeLists.txt

.include <bsd.port.mk>
