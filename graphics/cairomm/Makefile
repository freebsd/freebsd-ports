# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/cairomm/Makefile,v 1.19 2011/06/07 14:00:26 kwm Exp $

PORTNAME=	cairomm
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		cairo.2:${PORTSDIR}/graphics/cairo

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack ltverhack
CONFIGURE_ENV=	AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-documentation

.else
post-configure:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html
.endif

.include <bsd.port.mk>
