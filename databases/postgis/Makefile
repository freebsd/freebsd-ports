# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://postgis.refractions.net/download/ \
 		http://www.postgis.org/download/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj.6:${PORTSDIR}/graphics/proj \
		geos.0:${PORTSDIR}/graphics/geos
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

USE_BISON=	build
USE_PGSQL=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

OPTIONS=	LOADERGUI "Enable shp2pgsql-gui" Off

.include <bsd.port.options.mk>

INSTALL_TARGET=	install

GNU_CONFIGURE=	yes
.if defined(WITH_LOADERGUI)
USE_GNOME=	libxml2 gtk20
CONFIGURE_ARGS=	--with-projdir=${LOCALBASE} --with-gui
PLIST_SUB+=	LOADERGUI=""
.else
USE_GNOME=	libxml2
CONFIGURE_ARGS=	--with-projdir=${LOCALBASE}
PLIST_SUB+=	LOADERGUI="@comment "
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	DATADIR=${DATADIR} DOCSDIR=${DOCSDIR}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
CONFIGURE_ARGS+=	--with-xsldir=${LOCALBASE}/share/xsl/docbook
MAN1=		pgsql2shp.1 shp2pgsql.1
PORTDOCS=	*
.else
MAKE_ARGS+=	NOPORTDOCS=yes
.endif

post-extract:
	@${REINPLACE_CMD} -e 's#@ICONV_LDFLAGS@#-liconv -L${LOCALBASE}/lib#g' \
		${WRKSRC}/loader/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e 's#%PERL%#${PERL}#g' \
		${WRKSRC}/postgis/Makefile.in

post-install:
	@${MKDIR} ${DATADIR}/utils
	${INSTALL_SCRIPT} ${WRKSRC}/utils/create_undef.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/new_postgis_restore.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/profile_intersects.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/postgis_proc_upgrade.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/test_estimation.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/postgis_restore.pl ${DATADIR}/utils/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/test_joinestimation.pl ${DATADIR}/utils/
	@${MKDIR} ${PREFIX}/lib/postgresql
	@${LN} -s ${PREFIX}/lib/postgresql/postgis-1.5.so ${PREFIX}/lib/postgresql/postgis.so
	@${LN} -s ${PREFIX}/lib/postgresql/postgis-1.5.so ${PREFIX}/lib/postgresql/liblwgeom.so.1
	@${LN} -s ${PREFIX}/lib/postgresql/postgis-1.5.so ${PREFIX}/lib/postgresql/liblwgeom.so

.include <bsd.port.post.mk>
