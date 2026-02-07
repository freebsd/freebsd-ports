PORTNAME=	nurbs++
PORTVERSION=	3.0.11
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/libnurbs/nurbs%2B%2B/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ library to manipulate and create NURBS curves and surfaces
WWW=		https://libnurbs.sourceforge.net/

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GCC=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
