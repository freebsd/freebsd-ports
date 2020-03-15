# $FreeBSD$

PORTNAME=	tkgate
PORTVERSION=	2.1
CATEGORIES=	cad
MASTER_SITES=	http://cdn.bitbucket.org/starling13/tkgate/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Event driven digital circuit simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gnome iconv:translit libtool pkgconfig tk

USE_XORG=	x11 xft
USE_GNOME=	pango
OPTIONS_DEFINE=	DOCS
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%TCL_VER%%|${TCL_VER}|g; \
		s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
