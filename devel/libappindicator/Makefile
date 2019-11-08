# $FreeBSD$

PORTNAME=	libappindicator
PORTVERSION=	12.10.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	KSNI App Indicator library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu \
		libindicator3.so:devel/libindicator \
		libdbus-glib-1.so:devel/dbus-glib

USES=		gmake gnome libtool pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_GNOME=	gtk30 pygtk2

OPTIONS_DEFINE=	VAPI
OPTIONS_DEFAULT=	VAPI
OPTIONS_SUB=	yes

VAPI_BUILD_DEPENDS=	vala>=0:lang/vala
VAPI_CONFIGURE_ENV_OFF=	ac_cv_path_VALA_API_GEN= ac_cv_path_VALAC=
VAPI_VARS=	EXTRA_PATCHES+=${PATCHDIR}/extra-patch-bindings-vala-examples-Makefile.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3

.include <bsd.port.mk>
