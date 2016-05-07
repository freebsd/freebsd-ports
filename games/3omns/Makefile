# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3omns
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Old-school bomb-dropping Deathmatch

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:devel/argp-standalone \
		asciidoc:textproc/asciidoc \
		docbook-xml>0:textproc/docbook-xml \
		xsltproc:textproc/libxslt \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libxml2.so:textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_TAGNAME=	ded6410

USES=		autoreconf compiler:c++11-lang gmake pkgconfig lua:52
USE_SDL=	image2 sdl2 ttf2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -largp

PORTDOCS=	NEWS README
OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
