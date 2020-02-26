# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	graphics

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		meson ninja pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hellosiyan
GH_PROJECT=	Viewnior

USE_GNOME=	gdkpixbuf2 glib20 gtk20 intlhack intltool
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

pre-configure:
	${MKDIR} ${WRKSRC}/m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
