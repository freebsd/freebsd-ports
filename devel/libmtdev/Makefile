PORTNAME=	mtdev
PORTVERSION=	1.1.7
CATEGORIES=	devel
MASTER_SITES=	http://bitmath.org/code/${PORTNAME}/
PKGNAMEPREFIX=	lib

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Multitouch Protocol Translation Library
WWW=		https://bitmath.org/code/mtdev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		libtool localbase pathfix tar:bz2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
