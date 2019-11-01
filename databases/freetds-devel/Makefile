# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	1.1.71
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.freetds.org/files/current/ \
		ftp://ftp.freetds.org/pub/freetds/current/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-dev.${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library

LICENSE=	LGPL20

USES=		autoreconf compiler:c11 gettext-tools gmake iconv \
		libtool:keepla pkgconfig tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-dev.${PORTVERSION}
TDS_VER?=	7.4
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER} --sysconfdir=${ETCDIR} \
		--enable-msdblib --enable-sybase-compat \
		--docdir=${DOCSDIR}
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS ODBCWIDE
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		ODBC
OPTIONS_RADIO_ODBC=	IODBC UNIXODBC
ODBCWIDE_DESC=		Enable Wide ODBC Support
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
IODBC_CONFIGURE_ON=	--with-iodbc=${LOCALBASE}
IODBC_CPPFLAGS=		-I${LOCALBASE}/include/libiodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_CONFIGURE_ON=	--with-unixodbc=${LOCALBASE}
ODBCWIDE_CONFIGURE_ON=	--enable-odbc-wide

PORTDOCS=	*

CONFLICTS=	freetds-0.64.[0-9]

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MIODBC} || ${PORT_OPTIONS:MUNIXODBC}
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

post-extract:
	@cd ${WRKSRC} && ${LN} -s freetds.conf freetds.conf.sample
	@cd ${WRKSRC} && ${LN} -s locales.conf locales.conf.sample
	@cd ${WRKSRC}/src/pool && ${LN} -s pool.conf pool.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|libgnutls-config|pkg-config gnutls|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/pool.conf|/pool.conf.sample|g ; \
		 s| common.h||g ; \
		 s|%%DOCSDIR%%|${STAGEDIR}${DOCSDIR}|g ; \
		 s|%%ICONV_LIB%%|${ICONV_LIB}|'
	@${REINPLACE_CMD} -e 's|/freetds.conf|/freetds.conf.sample|g ; \
		 s|/locales.conf|/locales.conf.sample|g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|$$ODBC_INC/isql.h|$$ODBC_INC/libiodbc/isql.h|g ; \
		s|$$ODBC_INC/isqlext.h|$$ODBC_INC/libiodbc/isqlext.h|g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${ETCDIR}/interfaces.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/userguide
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/reference
	@${FIND} ${WRKSRC}/doc/userguide \( -type f -o -type l \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/userguide ';'
	@${FIND} ${WRKSRC}/doc/reference \( -type f -o -type l \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/reference ';'
	@cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}

.endif

.include <bsd.port.mk>
