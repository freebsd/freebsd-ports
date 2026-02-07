PORTNAME=	librevisa-vish
PORTVERSION=	0.0.20130714
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/
DISTNAME=	vish-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source VISA shell for interfacing test and measurement equipment
WWW=		http://www.librevisa.org/

LIB_DEPENDS=	libvisa.so:devel/librevisa

USES=		compiler:c++11-lang localbase:ldflags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

LDFLAGS+=	-lvisa

.include <bsd.port.mk>
