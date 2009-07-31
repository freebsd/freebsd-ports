# New ports collection makefile for:	py-goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/py-goocanvas/Makefile,v 1.6 2008/09/22 09:14:41 kwm Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.14.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/py${PORTNAME}/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GooCanvas python bindings

LIB_DEPENDS=	goocanvas.3:${PORTSDIR}/graphics/goocanvas

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/goocanvasmodule.la \
		%%PYTHON_SITELIBDIR%%/goocanvasmodule.so \
		libdata/pkgconfig/pygoocanvas.pc
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pygtk2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(PYGOBJECT_PYGDOCS)/style.css||; \
		s|demo docs|demo|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
