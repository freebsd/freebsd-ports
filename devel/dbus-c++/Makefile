# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	dbus-c++
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	pw
CATEGORIES=	devel gnome

MAINTAINER=	yuri@rawbw.com
COMMENT=	C++ API for D-BUS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus

BROKEN_FreeBSD_9=	Fails due to compiler issues

USE_GITHUB=	yes
GH_ACCOUNT=	andreas-volz
GH_PROJECT=	dbus-cplusplus

USES=		autoreconf compiler:c++11-lib gettext gmake libtool pkgconfig
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
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|^pkgconfigdir = .*|pkgconfigdir=$${prefix}/libdata/pkgconfig|' ${WRKSRC}/Makefile.am
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdbus-c++-1.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdbus-c++-glib-1.so

.include <bsd.port.mk>
