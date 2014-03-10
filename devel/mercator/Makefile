# Created by: Janni
# $FreeBSD$

PORTNAME=	mercator
PORTVERSION=	0.3.3
#PORTREVISION=	1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Mercator%20%28terrain%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A procedural terrain library

LIB_DEPENDS=	libwfmath-1.0.so:${PORTSDIR}/math/wfmath

CONFIGURE_ARGS=	--disable-silent-rules
USES=		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	yes
USE_GCC=	4.7+

CXXFLAGS+=	-include wchar.h

post-patch:
	@${REINPLACE_CMD} -e 's|std::lround|lround|g' ${WRKSRC}/Mercator/iround.h

.include <bsd.port.mk>
