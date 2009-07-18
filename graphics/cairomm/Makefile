# New ports collection makefile for:	cairomm
# Date created:		2005-12-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/graphics/cairomm/Makefile,v 1.4 2008/06/16 22:38:50 mezz Exp $
#

PORTNAME=	cairomm
PORTVERSION=	1.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs

post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/(docs|examples)//g' ${WRKSRC}/Makefile.in
.else
post-configure:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html
.endif

.include <bsd.port.mk>
