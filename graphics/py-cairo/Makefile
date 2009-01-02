# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.22 2007/03/14 21:38:08 ahze Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for Cairo

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pygtk
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|SUBDIRS = cairo examples test|SUBDIRS = cairo examples|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
