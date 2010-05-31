# New ports collection makefile for:	crow
# Date created:		11 May 2007
# Whom:			Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	crow
PORTVERSION=	2.15.0
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	SF/${PORTNAME}-designer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern GUI builder for the GTK+ toolkit

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		guiloader-c++.1:${PORTSDIR}/devel/guiloader-c++ \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	xdg-desktop-menu:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-hidden-visibility
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|hiddenvisibility|hidden_visibility|' ${WRKSRC}/configure

post-install:
	-@${LOCALBASE}/bin/update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
