# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e_dbus
PORTVERSION=	1.7.5
PORTEPOCH=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.fr/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	EFL DBUS connectivity library

LICENSE=	BSD

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina evas ecore libtool_hack librt_hack
USE_EFL_ECORE=	evas
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-ehal \
		--enable-eukit \
		--enable-enotify \
		--disable-econnman0_7x \
		--disable-eofono \
		--disable-ebluez

.include <bsd.port.mk>
