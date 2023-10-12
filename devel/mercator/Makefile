PORTNAME=	mercator
PORTVERSION=	0.3.3
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Mercator%20%28terrain%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Procedural terrain library
WWW=		https://www.worldforge.org/index.php/components/mercator/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	There has been no release for most of the Worldforge libraries in the past 10 years.
EXPIRATION_DATE=2023-12-31

LIB_DEPENDS=	libwfmath-1.0.so:math/wfmath

USES=		libtool pathfix pkgconfig compiler:c++11-lib
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CXXFLAGS+=	-include wchar.h

post-patch:
	@${REINPLACE_CMD} -e 's|std::lround|lround|g' ${WRKSRC}/Mercator/iround.h

.include <bsd.port.mk>
