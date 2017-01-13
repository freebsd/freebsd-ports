# Created by: alepulver
# $FreeBSD$

PORTNAME=	alienarena
PORTVERSION=	2013.766
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/alienarena.mirror/Alien%20Arena%207.66/ \
		http://icculus.org/alienarena/Files/ \
		http://red.planetarena.org/files/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
DISTNAME=	${PORTNAME}-7.66-linux20130827

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/data1/default.cfg:games/alienarena-data

USES=		compiler:c++11-lib dos2unix gmake
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKDIR}/${PORTNAME}-7.66/
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-xf86vm \
		--with-xf86dga \
		--with-system-libode

EXTRACT_AFTER_ARGS=	--exclude "data1"

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}-7.66/source

SUB_FILES=	pkg-message

OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

OPTIONS_DEFAULT=	CLIENT DEDICATED

PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USES+=		jpeg openal:soft,alut pkgconfig
LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis
BUILD_DEPENDS+=	${LOCALBASE}/lib/libode.a:devel/ode
USE_GL=		yes
USE_XORG=	xxf86dga xxf86vm
.endif

.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MDEDICATED}
CONFIGURE_ARGS+=--disable-client
.endif

.if ${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
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
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-ded \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-ded
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
