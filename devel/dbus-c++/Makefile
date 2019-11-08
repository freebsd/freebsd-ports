# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	dbus-c++
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	pw
PORTREVISION=	5
CATEGORIES=	devel gnome

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	7fca13b03d1d4af585714293358cf1f76664f41d.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ API for D-BUS

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus

USES=		autoreconf compiler:c++11-lib gettext gmake gnome libtool \
		localbase pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-volz
GH_PROJECT=	dbus-cplusplus
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
