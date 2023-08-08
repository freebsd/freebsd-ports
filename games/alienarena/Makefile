PORTNAME=	alienarena
PORTVERSION=	2013.766
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/alienarena/Files/ \
		http://red.planetarena.org/files/ \
		GENTOO
DISTNAME=	${PORTNAME}-7.66-linux20130827

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)
WWW=		http://red.planetarena.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/data1/default.cfg:games/alienarena-data

USES=		compiler:c++11-lib dos2unix gmake localbase
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xf86vm \
		--with-xf86dga \
		--with-system-libode

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"

# Fix build with clang11
CFLAGS+=	-fcommon

EXTRACT_AFTER_ARGS=	--exclude "data1"
SUB_FILES=	pkg-message

CONFIGURE_WRKSRC=${WRKDIR}/${PORTNAME}-7.66/
WRKSRC=		${WRKDIR}/${PORTNAME}-7.66/source

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
CLIENT_USES=		gl jpeg openal:soft,alut pkgconfig xorg
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
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/r_image.c
	${REINPLACE_CMD} -e 's|inline void IQM_DrawVBO|void IQM_DrawVBO|' \
		${WRKSRC}/ref_gl/r_iqm.c

do-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}/arena ${STAGEDIR}${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${STAGEDIR}${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${STAGEDIR}${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${STAGEDIR}${LIBDIR}/data1

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-ded \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-ded

.include <bsd.port.post.mk>
