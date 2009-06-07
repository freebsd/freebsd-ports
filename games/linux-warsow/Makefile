# New ports collection makefile for:	warsow
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.12
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	http://ftp.club-internet.fr/pub/games/nofrag/warsow/ \
		http://mirrors-av.club-internet.fr/pub/games/nofrag/warsow/ \
		http://kenh.rxvt.net/ \
		http://turkeyfiles.escapedturkey.net/warsow/versions/ \
		http://www.gizmo.fi/warsow/ \
		http://warsow.as-mirror.net/ \
		http://wsw.surreal-xenotronic.com/ \
		http://tmp.death-row.org/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free multiplayer first person shooter with cartoon design

IGNORE=		is outdated, does not match games/warsow-data port

RUN_DEPENDS=	${DATADIR}/data0.pk3:${PORTSDIR}/games/warsow-data

USE_LINUX=	yes
USE_LINUX_APPS=	openssl
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	warsow-wrapper wsw_server-wrapper
WARSOW_EXTRACT+=${PORTNAME}/basewsw/game${ARCHSUFFIX}.so
WARSOW_DIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${WARSOW_EXTRACT}

DESKTOP_ENTRIES="Warsow" \
		"Shoot cartoon enemies" \
		"" \
		"warsow" \
		"Application;Game;" \
		false

OPTIONS=	CLIENT	"Install client"	on \
		SERVER	"Install dedicated server"	on \
		NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least one of CLIENT and SERVER options
.endif

.if defined(WITH_NVIDIA)
.	if !exists(${LINUXBASE}/usr/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.	endif
.else
USE_LINUX_APPS+=dri
.endif

.if ${ARCH} == "i386"
ENGINESUFFIX=	""
ARCHSUFFIX=	"_i386"
PLIST_SUB+=	ENGINESUFFIX=${ENGINESUFFIX} \
		ARCHSUFFIX=${ARCHSUFFIX}
.elif ${ARCH} == "amd64"
ENGINESUFFIX=	".x86_64"
ARCHSUFFIX=	"_x86_64"
PLIST_SUB+=	ENGINESUFFIX=${ENGINESUFFIX} \
		ARCHSUFFIX=${ARCHSUFFIX}
.endif

.if !defined(WITHOUT_CLIENT)
USE_LINUX_APPS+=sdl12 libvorbis jpeg curl
PLIST_SUB+=	CLIENT=""
WARSOW_TARGET+=	warsow
WARSOW_EXTRACT+=${PORTNAME}/warsow${ENGINESUFFIX} \
		${PORTNAME}/basewsw/ui${ARCHSUFFIX}.so \
		${PORTNAME}/basewsw/cgame${ARCHSUFFIX}.so
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_SERVER)
PLIST_SUB+=	SERVER=""
WARSOW_TARGET+=	wsw_server
WARSOW_EXTRACT+=${PORTNAME}/wsw_server${ENGINESUFFIX}
.else
PLIST_SUB+=	SERVER="@comment "
.endif

do-install:
	${MKDIR} ${WARSOW_DIR}/basewsw
	${INSTALL_DATA} ${WRKSRC}/basewsw/*.so ${WARSOW_DIR}/basewsw
.for FILE in ${WARSOW_TARGET}
	${BRANDELF} -t Linux ${WRKSRC}/${FILE}${ENGINESUFFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE}${ENGINESUFFIX} ${WARSOW_DIR}/${FILE}
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE}-wrapper ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
.endfor
	${LN} -s ${DATADIR}/* ${WARSOW_DIR}/basewsw

.include <bsd.port.post.mk>
