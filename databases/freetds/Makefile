PORTNAME=	freetds
DISTVERSION=	1.5.6
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.freetds.org/files/stable/ \
		ftp://ftp.freetds.org/pub/freetds/stable/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library
WWW=		http://www.freetds.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		cpe gettext gmake iconv libtool:keepla localbase:ldflags \
		pkgconfig readline tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-msdblib \
		--enable-sybase-compat \
		--sysconfdir=${ETCDIR} \
		--with-tdsver=${TDS_VER}

INSTALL_TARGET=	install-strip

LIBS+=		-lgcrypt -lpthread

CONFLICTS=	freetds-devel

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS MARS
OPTIONS_DEFAULT=	MARS OPENSSL UNIXODBC
OPTIONS_SINGLE=		ODBC SSL
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL

MARS_DESC=	Enable MARS code (Experimental)

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
IODBC_CONFIGURE_ON=	--with-iodbc=${LOCALBASE}
IODBC_CPPFLAGS=		-I${LOCALBASE}/include/libiodbc
MARS_CONFIGURE_ON=	--enable-mars
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_CONFIGURE_ON=	--with-unixodbc=${LOCALBASE}

TDS_VER?=	7.4

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
	@${REINPLACE_CMD} -e 's|/freetds.conf|/freetds.conf.sample|g ; \
		s|/locales.conf|/locales.conf.sample|g ; \
		s| common.h||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/pool.conf|/pool.conf.sample|g' \
		${WRKSRC}/src/pool/Makefile.in
	@${REINPLACE_CMD} -e 's|\($$with_iodbc/include\)|\1/libiodbc|g ; \
		s| odbcss.h||g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${ETCDIR}/interfaces.sample

.include <bsd.port.mk>
