# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	graphics

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USE_GITHUB=	yes
GH_ACCOUNT=	xsisqox
GH_PROJECT=	Viewnior

USES=		autoreconf desktop-file-utils gmake libtool pkgconfig \
		gettext-tools
USE_GNOME=	glib20 gtk20 gdkpixbuf2 intltool intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

pre-configure:
	${MKDIR} ${WRKSRC}/m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
