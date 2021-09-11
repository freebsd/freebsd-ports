PORTNAME=	tagutil
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
CATEGORIES=	audio

MAINTAINER=	alex@kaworu.ch
COMMENT=	Command line interface tool to manage tags in music files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		cmake compiler:c++11-lang iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu

CMAKE_ARGS=	-DMAN_PATH=${PREFIX}/man
CMAKE_SOURCE_PATH=	${WRKSRC}/src

PLIST_FILES=	bin/tagutil \
		man/man1/tagutil.1.gz

OPTIONS_DEFINE=		JSON
OPTIONS_MULTI=		MEDIA
OPTIONS_MULTI_MEDIA=	FLAC OGG TAGLIB
OPTIONS_DEFAULT=	FLAC OGG TAGLIB

TAGLIB_DESC=		Multiple file format but limited tags support

JSON_LIB_DEPENDS=	libjansson.so:devel/jansson
JSON_CMAKE_OFF=		-DWITHOUT_JSON=yes

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_OFF=		-DWITHOUT_FLAC=yes

OGG_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
			libogg.so:audio/libogg
OGG_CMAKE_OFF=		-DWITHOUT_OGGVORBIS=yes

TAGLIB_LIB_DEPENDS=	libtag_c.so:audio/taglib
TAGLIB_CMAKE_OFF=	-DWITHOUT_TAGLIB=yes

.include <bsd.port.mk>
