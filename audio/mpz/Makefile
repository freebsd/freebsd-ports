PORTNAME=	mpz
PORTVERSION=	1.0.20
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Music player for big local collections

LICENSE=	GPLv3+

LIB_DEPENDS=	libtag.so:audio/taglib \
		libyaml-cpp.so:devel/yaml-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	olegantonyan

USES=		compiler:c++11-lang desktop-file-utils gstreamer qmake qt:5
USE_GSTREAMER=	flac libav mpg123 ogg opus vorbis
USE_QT=		buildtools_build concurrent core dbus gui multimedia \
		network widgets x11extras

QMAKE_ARGS=	DEFINES+=USE_SYSTEM_TAGLIB DEFINES+=USE_SYSTEM_YAMLCPP

post-extract:
	@${RM} -r ${WRKSRC}/libs/taglib ${WRKSRC}/libs/yaml-cpp

.include <bsd.port.mk>
