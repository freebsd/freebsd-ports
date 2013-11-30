# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialite
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Spatial Extensions for SQLite

LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libfreexl.so:${PORTSDIR}/textproc/freexl

WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig
USE_SQLITE=	yes
USE_GNOME=	libxml2

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=--enable-libxml2=yes CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure

BROKEN_powerpc=		Does not compile on powerpc: invokes i386 assembler

.include <bsd.port.mk>
