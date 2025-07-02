PORTNAME=	freetds
DISTVERSION=	1.5.95
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.freetds.org/files/current/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-dev.${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library - nightly snapshot
WWW=		http://www.freetds.org/

LICENSE=	LGPL20

USES=		compiler:c11 cpe gettext-tools gmake iconv \
	libtool:keepla localbase:ldflags pkgconfig tar:bzip2
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--enable-msdblib \
		--enable-sybase-compat \
		--sysconfdir=${ETCDIR} \
		--with-tdsver=${TDS_VER} \
		--mandir=${PREFIX}/share/man

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	freetds # etc/freetds/freetds.conf.sample

PORTSCOUT=	limit:^\d+\.\d+\.\d{3}$
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-dev.${PORTVERSION}

PORTDOCS=	*

TDS_VER?=	7.4

OPTIONS_DEFINE=		DOCS ODBCWIDE
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		ODBC
OPTIONS_RADIO_ODBC=	IODBC UNIXODBC
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
ODBCWIDE_DESC=		Enable Wide ODBC Support
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
IODBC_CONFIGURE_ON=	--with-iodbc=${LOCALBASE}
IODBC_CPPFLAGS=		-I${LOCALBASE}/include/libiodbc
ODBCWIDE_CONFIGURE_ON=	--enable-odbc-wide
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_CONFIGURE_ON=	--with-unixodbc=${LOCALBASE}

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
	@${REINPLACE_CMD} -e 's|/pool.conf|/pool.conf.sample|g' \
		${WRKSRC}/src/pool/Makefile.in
	@${REINPLACE_CMD} -e 's|/freetds.conf|/freetds.conf.sample|g ; \
		s|/locales.conf|/locales.conf.sample|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ ${ICONV_LIB}|g' \
		${WRKSRC}/src/tds/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${ETCDIR}/interfaces.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/userguide
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/reference
	@${FIND} ${WRKSRC}/doc/userguide \( -type f -o -type l \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/userguide ';'
	@${FIND} ${WRKSRC}/doc/reference \( -type f -o -type l \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/reference ';'
	@cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
