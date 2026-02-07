PORTNAME=	pdf2svg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Convert PDF to SVG
WWW=		https://cityinthesky.co.uk/opensource/pdf2svg/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USES=		gettext-runtime gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dawbarton
USE_GNOME=	cairo glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdf2svg

.include <bsd.port.mk>
