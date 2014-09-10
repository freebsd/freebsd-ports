# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3omns
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Old-school bomb-dropping Deathmatch

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone \
		asciidoc:${PORTSDIR}/textproc/asciidoc \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}:${PORTSDIR}/textproc/docbook-xml \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_PROJECT=	3omns
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	84f4b60

USES=		compiler:c++11-lang gmake pkgconfig lua:52
USE_SDL=	image2 sdl2 ttf2
USE_GNOME=	glib20
USE_AUTOTOOLS=	aclocal:env automake:env autoheader:env autoconf:env
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -largp

PORTDOCS=	NEWS README
OPTIONS_DEFINE=	DOCS

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -fi)

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
