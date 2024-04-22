PORTNAME=	librevisa
PORTVERSION=	0.0.20130412
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for interfacing test and measurement equipment
WWW=		http://www.librevisa.org/

USES=		gmake pathfix pkgconfig libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvisa.so

.include <bsd.port.mk>
