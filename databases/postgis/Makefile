# Created by: Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	1.5.3
PORTREVISION=	3
CATEGORIES=	databases geography
MASTER_SITES=	http://postgis.refractions.net/download/ \
		http://www.postgis.org/download/
PKGNAMESUFIX=	-legacy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		geos:${PORTSDIR}/graphics/geos
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

CONFLICTS=	postgis-2.*

DEPRECATED=	EOLed upstream
EXPIRATION_DATE=	2013-12-16

USES=		bison iconv gmake perl5
USE_GNOME=	libxml2
USE_PGSQL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=	LOADERGUI
LOADERGUI_DESC=	Enable shp2pgsql-gui

NO_STAGE=	yes
.include <bsd.port.options.mk>

INSTALL_TARGET=	install

.if ${PORT_OPTIONS:MLOADERGUI}
USE_GNOME+=	gtk20
CONFIGURE_ARGS=	--with-projdir=${LOCALBASE} --with-gui
PLIST_SUB+=	LOADERGUI=""
.else
CONFIGURE_ARGS=	--with-projdir=${LOCALBASE}
PLIST_SUB+=	LOADERGUI="@comment "
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	DATADIR=${DATADIR} DOCSDIR=${DOCSDIR}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
CONFIGURE_ARGS+=	--with-xsldir=${LOCALBASE}/share/xsl/docbook
MAN1=		pgsql2shp.1 shp2pgsql.1
PORTDOCS=	*
.else
MAKE_ARGS+=	NOPORTDOCS=yes
.endif

post-extract:
	@${REINPLACE_CMD} -e 's#@ICONV_LDFLAGS@#${ICONV_LIB} -L${LOCALBASE}/lib#g' \
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
