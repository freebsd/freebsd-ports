PORTNAME=	osm2pgrouting
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	converters databases geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Import OSM data into pgRouting database
WWW=		https://pgrouting.org/docs/tools/osm2pgrouting.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libpqxx.so:databases/postgresql-libpqxx

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/osm2pgrouting/mapconfig.xml|${PREFIX}/etc/${PORTNAME}/mapconfig.xml|' \
		${WRKSRC}/src/utilities/prog_options.cpp \
		${WRKSRC}/README.md

.include <bsd.port.mk>
