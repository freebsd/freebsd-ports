# New ports collection makefile for:	alienarena
# Date created:				11 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2009.733
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linux.kiev.ua/pub/Linux/Gentoo/distfiles/ \
		http://ftp.jeuxlinux.fr/files/ \
		http://mirror.ipgn.com.au/games/alienarena/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		http://offload2.icculus.org:9090/alienarena/Files/ \
		http://offload1.icculus.org:9090/alienarena/Files/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
DISTNAME=	${PORTNAME}7_33-linux20091227

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)

RUN_DEPENDS=	${DATADIR}/data1/default.cfg:${PORTSDIR}/games/alienarena-data

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}7_33/source

SUB_FILES=	pkg-message
ALL_TARGET=	build-release

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT)
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
USE_GL=		yes
USE_OPENAL=	soft alut
USE_XORG=	xxf86dga
.endif

.if defined(WITH_CLIENT) && defined(WITH_DEDICATED)
MAKE_ENV+=	BUILD=ALL
.elif defined(WITH_CLIENT)
MAKE_ENV+=	BUILD=CLIENT
.elif defined(WITH_DEDICATED)
MAKE_ENV+=	BUILD=DEDICATED
.else
IGNORE=		needs at least one executable (CLIENT or DEDICATED)
.endif

.if defined(WITH_CLIENT)
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=no
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/client/snd_openal.c
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/Makefile
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/r_image.c

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${WRKSRC}/release && \
		${INSTALL_PROGRAM} arena/game.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} game.so ${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${LIBDIR}/data1
.if defined(WITH_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crx \
		${PREFIX}/bin/${PORTNAME}
.endif
.if defined(WITH_DEDICATED)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crded \
		${PREFIX}/bin/${PORTNAME}-ded
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
