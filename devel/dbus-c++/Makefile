# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	dbus-c++
PORTVERSION=	0.9.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	pw
CATEGORIES=	devel gnome

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ API for D-BUS

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus

USE_GITHUB=	yes
GH_ACCOUNT=	andreas-volz
GH_PROJECT=	dbus-cplusplus

USES=		autoreconf compiler:c++11-lib gettext gmake libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--disable-ecore \
		--disable-static \
		--enable-glib \
		--disable-tests \
		--disable-examples \
		--disable-doxygen-docs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdbus-c++-1.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdbus-c++-glib-1.so

.include <bsd.port.mk>
