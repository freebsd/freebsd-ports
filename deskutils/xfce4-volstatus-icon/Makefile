# New ports collection makefile for:	xfce4-volstatus-icon
# Date created:		2010-08-04
# Whom:			Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xfce4-volstatus-icon
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Notification area icon that allows safe removal of removable devices

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
	hal.1:${PORTSDIR}/sysutils/hal

BROKEN=		Does not work with xfce 4.8

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XORG=	x11
USE_XFCE=	libexo libgui libutil
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib"

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

SUB_FILES=	pkg-message

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
