# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	1.1.23
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.freetds.org/files/stable/ \
		ftp://ftp.freetds.org/pub/freetds/stable/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		autoreconf gettext gmake iconv libtool:keepla pkgconfig readline tar:bzip2

TDS_VER?=	7.4

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lgcrypt -lpthread
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER} --sysconfdir=${ETCDIR} \
		--enable-sybase-compat --enable-msdblib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS MARS
OPTIONS_SINGLE=		SSL ODBC
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	OPENSSL MARS UNIXODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
IODBC_CONFIGURE_ON=	--with-iodbc=${LOCALBASE}
IODBC_CPPFLAGS=		-I${LOCALBASE}/include/libiodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_CONFIGURE_ON=	--with-unixodbc=${LOCALBASE}
MARS_DESC=	Enable MARS code (Experimental)
MARS_CONFIGURE_ON=	--enable-mars

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
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>| ; \
		 s|/freetds.conf|/freetds.conf.sample|g ; \
		 s|/locales.conf|/locales.conf.sample|g ; \
		 s|/pool.conf|/pool.conf.sample|g ; \
		 s| common.h||g'
	@${REINPLACE_CMD} -e 's|\($$with_iodbc/include\)|\1/libiodbc|g' \
		${WRKSRC}/configure.ac

post-install:
	${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${ETCDIR}/interfaces.sample

.include <bsd.port.mk>
