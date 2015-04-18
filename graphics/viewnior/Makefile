# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2

USE_GITHUB=	yes
GH_ACCOUNT=	xsisqox
GH_PROJECT=	Viewnior
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	fc0f5cb

USES=		autoreconf desktop-file-utils gmake libtool pkgconfig
USE_GNOME=	glib20 gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
