# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openrct2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
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
		libfreetype.so:print/freetype2 \
		libicuuc.so:devel/icu

USES=		cmake compiler:c++17-lang desktop-file-utils gnome gl iconv \
		localbase:ldflags pkgconfig sdl shared-mime-info ssl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenRCT2
GH_PROJECT=	OpenRCT2
GH_TUPLE=	OpenRCT2:objects:v1.0.10:objects \
		OpenRCT2:title-sequences:v0.1.2a:title_sequences
USE_GL=		gl
USE_LDCONFIG=	yes
USE_SDL=	sdl2

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DOWNLOAD_TITLE_SEQUENCES \
		DOWNLOAD_OBJECTS
CXXFLAGS+=	-D_GNU_SOURCE

PORTDATA=	*
PORTDOCS=	changelog.txt contributors.md licence.txt readme.txt

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/openrct2/config/Config.cpp

post-install:
	(cd ${WRKDIR}/title-sequences-0.1.2a; \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/title)
	(cd ${WRKDIR}/objects-1.0.10; \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/object)

.include <bsd.port.mk>
