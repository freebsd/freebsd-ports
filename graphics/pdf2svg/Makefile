# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	pdf2svg
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.cityinthesky.co.uk/wp-content/uploads/2013/10/

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Convert PDF to SVG

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USES=		pkgconfig
USE_GNOME=	cairo gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdf2svg

.include <bsd.port.mk>
