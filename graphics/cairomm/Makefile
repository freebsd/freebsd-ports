# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/cairomm/Makefile,v 1.19 2011/06/07 14:00:26 kwm Exp $

PORTNAME=	cairomm
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	cairo libxml++26
CONFIGURE_ENV=	AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-documentation

.else
post-configure:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcairomm-1.0.so.1.4.0

.include <bsd.port.mk>
