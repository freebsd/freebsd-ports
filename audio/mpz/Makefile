PORTNAME=	mpz
PORTVERSION=	2.1.6
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Music player for big local collections
WWW=		https://mpz-player.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libtag.so:audio/taglib \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang desktop-file-utils gstreamer
USE_GITHUB=	yes
GH_ACCOUNT=	olegantonyan
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis

CMAKE_ON=	USE_SYSTEM_LIBEBUR128 USE_SYSTEM_LIBMPDCLIENT \
		USE_SYSTEM_QHOTKEY USE_SYSTEM_SQLITE3 \
		USE_SYSTEM_TAGLIB USE_SYSTEM_YAMLCPP

OPTIONS_DEFINE=	GAPLESS QHOTKEY QT5
OPTIONS_DEFAULT=	GAPLESS QHOTKEY
QT5_PREVENTS=	GAPLESS

GAPLESS_DESC=	Gapless playback support (implies Qt 6)
GAPLESS_USES=	ebur128 sqlite
GAPLESS_CMAKE_OFF=	-DENABLE_GAPLESS:BOOL=OFF

QHOTKEY_DESC=	Global media-key hotkeys via QHotkey
QHOTKEY_LIB_DEPENDS=	libqhotkey.so:x11-toolkits/qhotkey@${_QT_RELNAME}
QHOTKEY_CMAKE_OFF=	-DENABLE_QHOTKEY:BOOL=OFF

QT5_USES=	qt:5
QT5_USES_OFF=	qt:6
QT5_USE=	QT=buildtools:build,qmake:build \
		QT=concurrent,core,dbus,gui,multimedia,network,svg,widgets
QT5_USE_OFF=	QT=base,multimedia,svg
QT5_CMAKE_ON=	-DUSE_QT5:BOOL=ON

post-extract:
	@${RM} -r ${WRKSRC}/3rdparty/[^i]*

.include <bsd.port.mk>

QT5_DESC+=	(default is Qt 6)
