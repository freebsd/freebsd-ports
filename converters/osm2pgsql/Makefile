# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	0.96.0
PORTREVISION=	5
CATEGORIES=	converters geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap

USES=		cmake compiler:c++11-lang lua:53 pgsql

CXXFLAGS+=	"-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1"

PLIST_FILES=	bin/osm2pgsql \
		man/man1/osm2pgsql.1.gz

PORTDOCS=	AUTHORS ChangeLog README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
