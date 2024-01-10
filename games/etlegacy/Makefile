PORTNAME=	etlegacy
DISTVERSION=	2.81.1
CATEGORIES=	games
MASTER_SITES=	https://mirror.etlegacy.com/geoip/:geoip \
		https://mirror.etlegacy.com/wolfadmin/:wolfadmin
DISTFILES=	wolfadmin.tar.gz:wolfadmin \
		GeoIP.dat.tar.gz:geoip
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	a second breath of life for Wolfenstein: Enemy Territory
WWW=		https://www.etlegacy.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake compiler:c++11-lib desktop-file-utils localbase \
		lua pkgconfig sqlite
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_TAGNAME=	956269f4c13ebe31ba2a0f0b805588383209bd5b

CMAKE_ARGS+=	-DCROSS_COMPILE32=OFF \
		-DBUNDLED_LIBS=OFF \
		-DBUNDLED_LIBS_DEFAULT=OFF \
		-DCLIENT_GLVND=ON \
		-DFEATURE_RENDERER2=OFF \
		-DENABLE_SSE=ON \
		-DFEATURE_AUTOUPDATE=OFF \
		-DINSTALL_DEFAULT_BASEDIR=${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFAULT=	CLIENT DEDICATED
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

CLIENT_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libcjson.so:devel/libcjson \
			libfreetype.so:print/freetype2 \
			libogg.so:audio/libogg \
			libpng.so:graphics/png \
			libvorbis.so:audio/libvorbis \
			libtheora.so:multimedia/libtheora
CLIENT_USES=		gl jpeg openal:soft,alut minizip sdl xorg
CLIENT_USE=		GL=gl,glu,glew SDL=sdl2 XORG=x11,xxf86dga,xxf86vm

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386="" \
		AMD64="@comment "
.elif ${ARCH} == "amd64"
PLIST_SUB+=	I386="@comment " \
		AMD64=""
.endif

.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MDEDICATED}
CMAKE_ARGS+=	-DBUILD_CLIENT=OFF
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/.build/legacy
	@cd ${WRKDIR}/.build/legacy && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/GeoIP.dat.tar.gz ${EXTRACT_AFTER_ARGS}
	@cd ${WRKDIR}/.build/legacy && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/wolfadmin.tar.gz ${EXTRACT_AFTER_ARGS}

post-patch:
	${REINPLACE_CMD} -e 's|AMD64|amd64|g' ${WRKSRC}/cmake/ETLPlatform.cmake

.include <bsd.port.post.mk>
