# New ports collection makefile for:	wsoundserver
# Date created:		9 December 1998
# Whom:			gljohns@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	wsoundserver
PORTVERSION=	0.4.0
CATEGORIES=	audio windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/
DISTNAME=	WSoundServer-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		dockapp.1:${PORTSDIR}/x11-wm/libdockapp \
		${ESD_DEPENDS}
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
MAKE_ARGS=	"-E CFLAGS"

.if defined(WITH_ESD)
ESD_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
CONFIGURE_ARGS+=--enable-esd
.else
ESD_DEPENDS=
.endif

MAN1=		get-wsound-flags.1x getsoundset.1x setsoundset.1x \
			wsoundplay.1x wsoundserver.1x

post-install:
	${SH} ${FILESDIR}/configure > ${WRKDIR}/WMSound
	${MKDIR} ${PREFIX}/etc/WindowMaker
	${INSTALL_DATA} ${WRKDIR}/WMSound \
		${PREFIX}/etc/WindowMaker/WMSound

.include <bsd.port.mk>
