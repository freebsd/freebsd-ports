# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	pdf2svg
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.cityinthesky.co.uk/_media/opensource/

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Convert PDF to SVG

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		cairo:${PORTSDIR}/graphics/cairo \
		gtk:${PORTSDIR}/x11-toolkits/gtk20

USES=		pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdf2svg

NO_STAGE=	yes
.include <bsd.port.mk>
