# Created by: gahr
# $FreeBSD$

PORTNAME=	speedtables
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High-performance memory-resident database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtclx8.4.so:${PORTSDIR}/lang/tclX \
		libboost_graph.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS PGSQL
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_LIB_DEPENDS=	libpgtcl2.0.0.so:${PORTSDIR}/databases/postgresql94-pgtcl

PORTDOCS=	*

USES=		tcl

USE_AUTOTOOLS=	autoconf
USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-boost=${PREFIX} \
		--with-tcl=${TCL_LIBDIR}

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ctables/docs/manual && \
	    ${COPYTREE_SHARE} \*.html ${STAGEDIR}${DOCSDIR} && \
	    ${COPYTREE_SHARE} \*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
