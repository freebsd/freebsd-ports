# Created by: Janni
# $FreeBSD$

PORTNAME=	mercator
PORTVERSION=	0.3.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Mercator%20%28terrain%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Procedural terrain library

LIB_DEPENDS=	libwfmath-1.0.so:math/wfmath

USES=		libtool pathfix pkgconfig compiler:c++11-lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-include wchar.h

post-patch:
	@${REINPLACE_CMD} -e 's|std::lround|lround|g' ${WRKSRC}/Mercator/iround.h

.include <bsd.port.mk>
