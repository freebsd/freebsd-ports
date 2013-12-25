# Created by: alepulver
# $FreeBSD$

PORTNAME=	alienarena
PORTVERSION=	2013.766
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linux.kiev.ua/pub/Linux/Gentoo/distfiles/ \
		http://ftp.jeuxlinux.fr/files/ \
		http://mirror.ipgn.com.au/games/alienarena/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		http://offload2.icculus.org:9090/alienarena/Files/ \
		http://offload1.icculus.org:9090/alienarena/Files/ \
		http://icculus.org/alienarena/Files/ \
		http://red.planetarena.org/files/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
DISTNAME=	${PORTNAME}-7.66-linux20130827

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)

RUN_DEPENDS=	${DATADIR}/data1/default.cfg:${PORTSDIR}/games/alienarena-data

USES=		dos2unix gmake
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKDIR}/${PORTNAME}-7.66/
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=--with-xf86vm \
		--with-xf86dga

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USES+=		openal:soft,alut pkgconfig
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
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
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/client/snd_openal.c
	@${REINPLACE_CMD} -e "s|.codered|.config/alienarena|g" ${WRKSRC}/qcommon/qcommon.h
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/r_image.c

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${LIBDIR}/data1
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-ded \
		${PREFIX}/bin/${PORTNAME}-ded
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
