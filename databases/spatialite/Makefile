# New ports collection makefile for:	spatialite
# Date created:				11 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	spatialite
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Spatial Extensions for SQLite

LIB_DEPENDS=	geos_c.9:${PORTSDIR}/graphics/geos \
		proj.7:${PORTSDIR}/graphics/proj \
		freexl.1:${PORTSDIR}/textproc/freexl

EXTRACT_SUFX =	.tar.gz
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SQLITE=	yes
USES=		iconv

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: invokes i386 assembler
.endif

.include <bsd.port.post.mk>
