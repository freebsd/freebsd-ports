# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.64
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/${FEDORALOC}/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Sybase/Microsoft TDS protocol library

TDS_VER?=	5.0

USES=		iconv gmake libtool:keepla
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
FEDORALOC=	freetds/freetds-0.64.tar.gz/ecfee5d6c96932172a1f29fb215c9d23

PORTDOCS=	*

OPTIONS_DEFINE=	OPENSSL GNUTLS MSDBLIB DOCS
OPTIONS_RADIO=	ODBC
OPTIONS_RADIO_ODBC=	IODBC UNIXODBC
MSDBLIB_DESC=	MS SQL Server support (breaks databases/sybtcl)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls
.endif

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	libiodbc.so:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
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
.endif

post-extract:
	@cd ${WRKSRC} && ${LN} -s freetds.conf freetds.conf.dist
	@cd ${WRKSRC} && ${LN} -s locales.conf locales.conf.dist
	@cd ${WRKSRC}/src/pool && ${LN} -s pool.conf pool.conf.dist

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>| ; \
		 s|/freetds.conf|/freetds.conf.dist|g ; \
		 s|/locales.conf|/locales.conf.dist|g ; \
		 s|/pool.conf|/pool.conf.dist|g ; \
		 s| common.h||g'

post-install:
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/freetds
	@${INSTALL_DATA} ${WRKSRC}/interfaces ${STAGEDIR}${PREFIX}/etc/freetds/interfaces.dist
	@${ECHO_CMD} "Sample configuration files have been installed in ${PREFIX}/etc"
	@${ECHO_CMD} "You should edit them and remove the .dist-suffix from their names"

.include <bsd.port.mk>
