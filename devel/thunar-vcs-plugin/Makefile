# New ports collection makefile for:	thunar-svn-plugin
# Date created: 	2008-10-15
# Whom:			Sergey V. Dyatko <sergey.dyatko@gmail.com>
#	
# $FreeBSD$
#

PORTNAME=	thunar-svn-plugin
PORTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	devel xfce
MASTER_SITES=	http://goodies.xfce.org/releases/thunar-svn-plugin/
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Subversion plugin for Thunar

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_XFCE=	configenv libexo thunar

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

.include <bsd.port.post.mk>
