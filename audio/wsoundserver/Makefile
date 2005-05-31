# New ports collection makefile for:	wsoundserver
# Date created:		9 December 1998
# Whom:			gljohns@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	wsoundserver
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	WSoundServer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The sound server for Window Maker

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		dockapp.1:${PORTSDIR}/x11-wm/libdockapp
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include/WINGs"

MAN1=		get-wsound-flags.1x getsoundset.1x setsoundset.1x \
			wsoundplay.1x wsoundserver.1x

post-install:
	${SH} ${FILESDIR}/configure > ${WRKDIR}/WMSound
	${MKDIR} ${PREFIX}/etc/WindowMaker
	${INSTALL_DATA} ${WRKDIR}/WMSound \
		${PREFIX}/etc/WindowMaker/WMSound

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
PKGNAMESUFFIX=	-esound
.endif

.include <bsd.port.post.mk>
