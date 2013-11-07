# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.92.79
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.freetds.org/pub/freetds/stable/
PKGNAMESUFFIX=	-devel

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Sybase/Microsoft TDS protocol library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TDS_VER?=	5.0
USES=		gmake iconv pkgconfig
GNU_GONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env libtool
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER}
USE_LDCONFIG=	yes

PORTDOCS=	*

MAN1=		datacopy.1 freebcp.1 tsql.1 bsqldb.1 bsqlodbc.1 \
		defncopy.1 fisql.1 osql.1
MAN5=		freetds.conf.5

# OPTIONS_DEFINE=	OPENSSL GNUTLS IODBC UNIXODBC MSDBLIB
OPTIONS_DEFINE=	MSDBLIB ODBCWIDE

OPTIONS_SINGLE=	ODBC SSL
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS

OPTIONS_DEFAULT=	OPENSSL IODBC

OPENSSL_DESC=	Use OpenSSL
GNUTLS_DESC=	Use GnuTLS
IODBC_DESC=	Depend on iodbc
UNIXODBC_DESC=	Depend on unixodbc
MSDBLIB_DESC=	MS SQL Server compatibility (breaks databases/sybtcl)
ODBCWIDE_DESC=	Enable Wide ODBC Support

CONFLICTS=	freetds-0.64.[0-9]

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:ODBCWIDE}
CONFIGURE_ARGS+=	--enable-odbc-wide
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.endif

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MIODBC} || ${PORT_OPTIONS:MUNIXODBC}
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

# We cannot use msdblib-style by default, because port databases/sybtcl
# relies on sybase-style dblib
.if ${PORT_OPTIONS:MMSDBLIB}
CONFIGURE_ARGS+=	--enable-msdblib
TDS_VER=	7.2
.endif

post-extract:
	@cd ${WRKSRC} && ${LN} -s freetds.conf freetds.conf.dist
	@cd ${WRKSRC} && ${LN} -s locales.conf locales.conf.dist
	@cd ${WRKSRC}/src/pool && ${LN} -s pool.conf pool.conf.dist

post-patch:
	@${REINPLACE_CMD} -e 's|libgnutls-config|pkg-config gnutls|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>| ; \
		 s|/freetds.conf|/freetds.conf.dist|g ; \
		 s|/locales.conf|/locales.conf.dist|g ; \
		 s|/pool.conf|/pool.conf.dist|g ; \
		 s| common.h||g ; \
		 s|%%ICONV_LIB%%|${ICONV_LIB}|'

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc/${PORTNAME}-${PORTVERSION}/reference ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc/${PORTNAME}-${PORTVERSION}/userguide ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/etc/freetds
	@${INSTALL_DATA} ${WRKSRC}/interfaces ${PREFIX}/etc/freetds/interfaces.dist
	@${ECHO_CMD} "Sample configuration files have been installed in ${PREFIX}/etc"
	@${ECHO_CMD} "You should edit them and remove the .dist-suffix from their names"

.include <bsd.port.mk>
