PORTNAME=	libuninum
PORTVERSION=	2.7
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for converting Unicode strings to numbers
WWW=		https://billposer.org/Software/libuninum.html

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool localbase tar:bz2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
