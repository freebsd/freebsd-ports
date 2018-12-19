# $FreeBSD$

PORTNAME=	mtdev
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bitmath.org/code/${PORTNAME}/
PKGNAMEPREFIX=	lib

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Multitouch Protocol Translation Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		libtool pathfix tar:bz2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include # evdev-proto
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
