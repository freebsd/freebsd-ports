# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.8.10
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py2${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for Cairo

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

WRKSRC=		${WRKDIR}/py${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.6-2.7
USES=	pathfix gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|SUBDIRS = cairo examples test|SUBDIRS = cairo examples|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
