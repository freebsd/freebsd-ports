# New ports collection makefile for:	crow
# Date created:		11 May 2007
# Whom:			Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	crow
PORTVERSION=	2.11.2
CATEGORIES=	devel gnome
MASTER_SITES=	SF/crow-designer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern GUI builder for the GTK+ toolkit

BUILD_DEPENDS=	guiloader-c++>=2.10.1:${PORTSDIR}/devel/guiloader-c++
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	guiloader-c++>=2.10.1:${PORTSDIR}/devel/guiloader-c++ \
		xdg-desktop-menu:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Fails to compile
.endif

.include <bsd.port.post.mk>
