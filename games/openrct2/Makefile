# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openrct2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open source re-implementation of RollerCoaster Tycoon 2

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/licence.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libjansson.so:devel/jansson \
		libzip.so:archivers/libzip \
		libspeexdsp.so:audio/speexdsp \
		libfontconfig.so:x11-fonts/fontconfig \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2

USES=		compiler:c++14-lang cmake:outsource desktop-file-utils iconv localbase:ldflags pkgconfig shared-mime-info ssl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenRCT2
GH_PROJECT=	OpenRCT2
USE_GL=		gl
USE_LDCONFIG=	yes
USE_SDL=	sdl2
INSTALLS_ICONS=	yes
SUB_FILES=	pkg-message
SUB_LIST=	DISTVERSIONPREFIX=${DISTVERSIONPREFIX} \
		DISTVERSION=${DISTVERSION} \
		PORTNAME=${PORTNAME}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DOWNLOAD_TITLE_SEQUENCES

OPTIONS_DEFINE=	DOCS
PORTDOCS=	changelog.txt contributors.md licence.txt readme.txt

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/openrct2/config/Config.cpp

.include <bsd.port.mk>
