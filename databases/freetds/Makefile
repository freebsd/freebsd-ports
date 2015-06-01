# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.91.112.0.0
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.freetds.org/pub/freetds/stable/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

PORTSCOUT=	skipv:0.92.48,0.92.49,0.92,51,0.92.52,0.92.53,0.92.54,0.92.55,0.92.59,0.92.63,0.92.79,0.92.405
TDS_VER?=	5.0

USES=		autoreconf iconv gmake pkgconfig libtool:keepla tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lgcrypt
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER} --sysconfdir=${ETCDIR} \
	       	--enable-sybase-compat --enable-msdblib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		ODBC
OPTIONS_RADIO_ODBC=	IODBC UNIXODBC
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
IODBC_LIB_DEPENDS=	libiodbc.so:${PORTSDIR}/databases/libiodbc
IODBC_CONFIGURE_ON=	--with-iodbc=${LOCALBASE}
IODBC_CPPFLAGS=		-I${LOCALBASE}/include/libiodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
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
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>| ; \
		 s|/freetds.conf|/freetds.conf.sample|g ; \
		 s|/locales.conf|/locales.conf.sample|g ; \
		 s|/pool.conf|/pool.conf.sample|g ; \
		 s| common.h||g'
	@${REINPLACE_CMD} -e 's|$$ODBC_INC/isql.h|$$ODBC_INC/libiodbc/isql.h|g ; \
		 s|$$ODBC_INC/isqlext.h|$$ODBC_INC/libiodbc/isqlext.h|g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${ETCDIR}/interfaces.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/doc/${PORTNAME}-${PORTVERSION} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
