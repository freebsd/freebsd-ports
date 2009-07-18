# New ports collection makefile for:	alienarena
# Date created:				11 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2008.721
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linux.kiev.ua/pub/Linux/Gentoo/distfiles/ \
		http://ftp.jeuxlinux.fr/files/ \
		http://mirror.ipgn.com.au/games/alienarena/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		http://offload2.icculus.org:9090/alienarena/Files/ \
		http://offload1.icculus.org:9090/alienarena/Files/
DISTNAME=	${PORTNAME}2008-linux20090109

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (native version)

RUN_DEPENDS=	${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}2008/source
ALL_TARGET=	build-release

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL sound client (needs CLIENT)" on

PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
USE_GL=		yes
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

.if defined(WITH_SDL)
USE_SDL=	sdl
PLIST_SUB+=	SDL=""
.else
MAKE_ENV+=	SDLSOUND=0
PLIST_SUB+=	SDL="@comment "
.endif

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
.if defined(WITH_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crx.sdl \
		${PREFIX}/bin/${PORTNAME}-sdl
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
