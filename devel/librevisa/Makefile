PORTNAME=	librevisa
PORTVERSION=	0.0.20130412
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for interfacing test and measurement equipment

USES=		gmake pathfix pkgconfig libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvisa.so

.include <bsd.port.mk>
