# New ports collection makefile for:	py-goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/py-goocanvas/Makefile,v 1.4 2008/02/27 16:19:50 ahze Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.9.0
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GooCanvas python bindings

LIB_DEPENDS=	goocanvas.3:${PORTSDIR}/graphics/goocanvas

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/goocanvasmodule.la \
		%%PYTHON_SITELIBDIR%%/goocanvasmodule.so
USE_PYTHON=	yes
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
