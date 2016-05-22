# Created by: gahr
# $FreeBSD$

PORTNAME=	speedtables
PORTVERSION=	1.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-performance memory-resident database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtclx8.4.so:lang/tclX \
		libboost_graph.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USES=		autoreconf tcl:tea
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}
MAKE_ENV=	TCLSH=${TCLSH}
TEST_TARGET=	test

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS PGSQL CASSANDRA
CASSANDRA_DESC=		Cassandra database support
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_LIB_DEPENDS=	libpgtcl2.0.0.so:databases/postgresql94-pgtcl
CASSANDRA_CONFIGURE_ON=	--with-casstcl=${LOCALBASE}
CASSANDRA_LIB_DEPENDS=	libcasstcl.so:databases/casstcl

post-configure:
	${CHMOD} a+x ${WRKSRC}/ctable_server/sttp
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ctables/docs/manual && \
	    ${COPYTREE_SHARE} \*.html ${STAGEDIR}${DOCSDIR} && \
	    ${COPYTREE_SHARE} \*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
