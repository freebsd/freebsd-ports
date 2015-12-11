# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e_dbus
PORTVERSION=	1.7.10
PORTEPOCH=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL DBUS connectivity library

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:${PORTSDIR}/devel/efl \
		libdbus-1.so:${PORTSDIR}/devel/dbus

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-ehal --disable-enotify --disable-eukit \
		--disable-econnman0_7x --disable-eofono --disable-ebluez \
		--disable-edbus-test --disable-edbus-test-client \
		--disable-edbus-async-test --disable-static

DEPRECATED=	Not used anymore by x11-wm/enlightenment
EXPIRATION_DATE=2016-01-15

.include <bsd.port.mk>
