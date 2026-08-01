PORTNAME=	mpz
PORTVERSION=	2.1.2
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Music player for big local collections
WWW=		https://mpz-player.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libtag.so:audio/taglib \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang desktop-file-utils gstreamer qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	olegantonyan
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis
USE_QT=		buildtools:build qmake:build concurrent core dbus gui \
		multimedia network svg widgets

CMAKE_ON=	USE_QT5 USE_SYSTEM_LIBMPDCLIENT USE_SYSTEM_QHOTKEY \
		USE_SYSTEM_TAGLIB USE_SYSTEM_YAMLCPP

OPTIONS_DEFINE=	QHOTKEY
OPTIONS_DEFAULT=	QHOTKEY

QHOTKEY_DESC=	Global media-key hotkeys via QHotkey
QHOTKEY_LIB_DEPENDS=	libqhotkey.so:x11-toolkits/qhotkey@qt5
QHOTKEY_CMAKE_OFF=	-DENABLE_QHOTKEY:BOOL=OFF

post-extract:
	@${RM} -r ${WRKSRC}/3rdparty/[^i]*

.include <bsd.port.mk>
