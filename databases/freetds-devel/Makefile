# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.92.79
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.freetds.org/pub/freetds/stable/
PKGNAMESUFFIX=	-devel

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library

LICENSE=	LGPL20

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TDS_VER?=	5.0
USES=		gmake iconv libtool:keepla pkgconfig
GNU_GONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER}
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

PORTDOCS=	*

# OPTIONS_DEFINE=	OPENSSL GNUTLS IODBC UNIXODBC MSDBLIB
OPTIONS_DEFINE=	MSDBLIB ODBCWIDE ODBC

OPTIONS_SINGLE=	SSL
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS

OPTIONS_DEFAULT=	OPENSSL

OPENSSL_DESC=	Use OpenSSL
GNUTLS_DESC=	Use GnuTLS
MSDBLIB_DESC=	MS SQL Server compatibility (breaks databases/sybtcl)
ODBCWIDE_DESC=	Enable Wide ODBC Support
ODBC_DESC=	ODBC driver

CONFLICTS=	freetds-0.64.[0-9]

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MODBCWIDE}
CONFIGURE_ARGS+=	--enable-odbc-wide
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.endif

LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc/${PORTNAME}-${PORTVERSION}/reference ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc/${PORTNAME}-${PORTVERSION}/userguide ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/freetds
	@${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${PREFIX}/etc/freetds/interfaces.dist

.include <bsd.port.mk>
