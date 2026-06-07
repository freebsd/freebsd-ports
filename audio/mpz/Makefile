PORTNAME=	mpz
DISTVERSION=	2.0.10
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Music player for big local collections
WWW=		https://mpz-player.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libtag.so:audio/taglib \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang desktop-file-utils gl gstreamer qt:6 \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	olegantonyan
USE_GL=		opengl
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis
USE_QT=		base multimedia tools:build
USE_XORG=	ice sm x11 xext xorgproto

CMAKE_ON=	USE_SYSTEM_LIBMPDCLIENT USE_SYSTEM_TAGLIB USE_SYSTEM_YAMLCPP

.include <bsd.port.mk>
