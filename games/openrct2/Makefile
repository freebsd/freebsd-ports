# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openrct2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	games
EXTRACT_ONLY=	${PORTNAME}-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}_GH0${EXTRACT_SUFX}

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

USE_GITHUB=	yes

WRKSRC=		${WRKDIR}/OpenRCT2-${PORTVERSION}
INSTALLS_ICONS=	yes
USES=		compiler:c++14-lang cmake:outsource iconv localbase:ldflags pkgconfig ssl
USE_GL=		gl
USE_LDCONFIG=	yes
USE_SDL=	sdl2
SUB_FILES=	pkg-message
SUB_LIST=	DISTVERSIONPREFIX=${DISTVERSIONPREFIX} \
		DISTVERSION=${DISTVERSION} \
		PORTNAME=${PORTNAME}
CMAKE_ARGS=	-DDOWNLOAD_TITLE_SEQUENCES=OFF

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/openrct2/config/Config.cpp

.include <bsd.port.mk>
