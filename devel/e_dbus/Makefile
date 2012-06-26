# New ports collection makefile for:	e_dbus
# Date created:				23 February 2008
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e_dbus
DISTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/

MAINTAINER=	magik@roorback.net
COMMENT=	EFL DBUS connectivity library

LICENSE=	BSD

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina evas ecore libtool_hack librt_hack
USE_EFL_ECORE=	evas
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-ehal \
		--enable-eukit \
		--enable-econnman0_7x \
		--enable-eofono \
		--enable-enotify \
		--disable-ebluez  # Linux specific ??

.include <bsd.port.mk>
