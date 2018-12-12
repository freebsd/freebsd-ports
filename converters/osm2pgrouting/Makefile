# $FreeBSD$

PORTNAME=	osm2pgrouting
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3
PORTREVISION=	6
CATEGORIES=	converters databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Import OSM data into pgRouting database

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libpqxx.so:databases/postgresql-libpqxx

USES=		cmake:outsource compiler:c++11-lang pgsql
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting
WANT_PGSQL=	client

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Readme.md

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/osm2pgrouting/mapconfig.xml|${PREFIX}/etc/mapconfig.xml|' \
		${WRKSRC}/src/utilities/prog_options.cpp \
		${WRKSRC}/Readme.md

post-install:
	@for cf in ${STAGEDIR}${PREFIX}/etc/*.xml; do \
		${MV} $${cf} $${cf}.sample; \
	done

.include <bsd.port.mk>
