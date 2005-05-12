# New ports collection makefile for:	rapidsvn
# Date created:		Jan 1, 2005
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rapidsvn
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://www.rapidsvn.org/download/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Cross-platform GUI front-end for the Subversion revision system

BUILD_DEPENDS=	apr-1-config:${PORTSDIR}/devel/apr-svn \
		${WXCONFIG}:${PORTSDIR}/x11-toolkits/${WXPORT} \
		neon-config:${PORTSDIR}/www/neon \
		${SVNDEP}:${PORTSDIR}/devel/subversion

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_AUTOCONF_VER=	259
CONFIGURE_ARGS=	--with-wx-config=${WXCONFIG} \
	--with-apr-config=apr-1-config \
	--with-apu-config=apu-1-config
CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes
MAN1=		rapidsvn.1

.if exists(${X11BASE}/bin/wxgtk2-2.5-config)
WXPORT=		wxgtk2-devel
WXCONFIG=	wxgtk2-2.5-config
.else
WXPORT=		wxgtk24
WXCONFIG=	wx-config
.endif
SVNDEP=		${LOCALBASE}/include/subversion-1/svn_types.h

.include <bsd.port.mk>
