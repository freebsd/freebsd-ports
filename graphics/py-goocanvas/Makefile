# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/graphics/py-goocanvas/Makefile,v 1.6 2008/09/22 09:14:41 kwm Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.14.1
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	GNOME/sources/py${PORTNAME}/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GooCanvas python bindings

LIB_DEPENDS=	libgoocanvas.so:graphics/goocanvas

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/goocanvasmodule.so \
		libdata/pkgconfig/pygoocanvas.pc
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs
USES=		gmake libtool pathfix pkgconfig python tar:bzip2
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|$$(PYGOBJECT_PYGDOCS)/style.css||; \
		s|demo docs|demo|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
