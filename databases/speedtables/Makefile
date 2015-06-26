# Created by: gahr
# $FreeBSD$

PORTNAME=	speedtables
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-performance memory-resident database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtclx8.4.so:${PORTSDIR}/lang/tclX \
		libboost_graph.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USES=		autoreconf tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-boost=${PREFIX} \
		--with-tcl=${TCL_LIBDIR}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS PGSQL
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_LIB_DEPENDS=	libpgtcl2.0.0.so:${PORTSDIR}/databases/postgresql94-pgtcl

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ctables/docs/manual && \
	    ${COPYTREE_SHARE} \*.html ${STAGEDIR}${DOCSDIR} && \
	    ${COPYTREE_SHARE} \*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
