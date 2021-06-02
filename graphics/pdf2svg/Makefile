# Created by: Martin Dieringer <martin.dieringe@gmx.de>

PORTNAME=	pdf2svg
PORTVERSION=	0.2.3
PORTREVISION=	30
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Convert PDF to SVG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USE_GITHUB=	yes
GH_ACCOUNT=	db9052

USES=		gnome pkgconfig
USE_GNOME=	cairo
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdf2svg

.include <bsd.port.mk>
