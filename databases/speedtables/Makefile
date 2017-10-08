# Created by: gahr
# $FreeBSD$

PORTNAME=	speedtables
PORTVERSION=	1.13.8
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-performance memory-resident database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtclx8.4.so:lang/tclX \
		libboost_graph.so:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib/ncgi/ncgi.tcl:devel/tcllib

USES=		autoreconf tcl:tea
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}
MAKE_ENV=	TCLSH=${TCLSH}
TEST_TARGET=	test

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS PGSQL CASSANDRA
CASSANDRA_DESC=		Cassandra database support
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_LIB_DEPENDS=	libpgtcl2.0.0.so:databases/postgresql94-pgtcl
CASSANDRA_CONFIGURE_ON=	--with-casstcl=${LOCALBASE}
CASSANDRA_LIB_DEPENDS=	libcasstcl.so:databases/casstcl

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ctables/docs/manual && \
	    ${COPYTREE_SHARE} \*.html ${STAGEDIR}${DOCSDIR} && \
	    ${COPYTREE_SHARE} \*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
