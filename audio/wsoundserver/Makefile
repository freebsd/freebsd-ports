# New ports collection makefile for:	wsoundserver
# Date created:		9 December 1998
# Whom:			gljohns@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	wsoundserver
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	audio windowmaker
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	WSoundServer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The sound server for Window Maker

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		dockapp.2:${PORTSDIR}/x11-wm/libdockapp
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_AUTOTOOLS=	libtool:22
WANT_GNOME=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/WINGs"
CONFIGURE_ARGS+=--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-libs-from=-L${LOCALBASE}/lib \
		--with-incs-from=-I{LOCALBASE}/include

MAN1=		get-wsound-flags.1x getsoundset.1x setsoundset.1x \
			wsoundplay.1x wsoundserver.1x

post-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure > ${WRKDIR}/WMSound
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
