PORTNAME=	alienarena
DISTVERSION=	7.71.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)
WWW=		https://alienarena.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../docs/license.txt

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/arena/default.cfg:games/alienarena-data

USES=		compiler:c++11-lib desktop-file-utils dos2unix gmake localbase pkgconfig
USE_CXXSTD=	c++11
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xf86vm \
		--with-xf86dga \
		--with-system-libode

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"

# Fix build with clang11
CFLAGS+=	-fcommon -Wno-error=int-conversion

EXTRACT_AFTER_ARGS=	--exclude "data1"
SUB_FILES=	pkg-message

CONFIGURE_WRKSRC=${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/source

PLIST_SUB+=	LIBDIR=${LIBDIR:S|^${PREFIX}/||}

OPTIONS_DEFAULT=	CLIENT DEDICATED
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

CLIENT_LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libode.so:devel/ode
CLIENT_USES=		gl jpeg openal:soft,alut minizip xorg
CLIENT_USE=		GL=glu XORG=x11,xxf86dga,xxf86vm

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MDEDICATED}
CONFIGURE_ARGS+=--disable-client
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|(CCLD)|(CXX)|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/client/snd_openal.c
	@${REINPLACE_CMD} -e "s|.codered|.config/alienarena|g" ${WRKSRC}/qcommon/qcommon.h
	@${REINPLACE_CMD} -e "s|/usr/games/alien-arena|${PORTNAME}|g" ${WRKSRC}/../unix_dist/alien-arena.desktop
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/r_image.c
	${REINPLACE_CMD} -e 's|inline void IQM_DrawVBO|void IQM_DrawVBO|' \
		${WRKSRC}/ref_gl/r_iqm.c

do-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}/arena ${STAGEDIR}${LIBDIR}/data1
	${LN} -sf ${DATADIR}/arena/* ${STAGEDIR}${LIBDIR}/arena
	${LN} -sf ${DATADIR}/data1/* ${STAGEDIR}${LIBDIR}/data1

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${INSTALL_DATA} ${WRKSRC}/../unix_dist/alien-arena.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/../unix_dist/alien-arena.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-ded \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-ded

.include <bsd.port.post.mk>
