# New ports collection makefile for:   freetds-devel
# Date created:		02 Nov 1999
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.82.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/${PORTNAME}/stable
PKGNAMESUFFIX=	-devel
DISTNAME=	freetds-patched
EXTRACT_SUFX=	.tgz

MAINTAINER?=	cowbert@gmail.com
COMMENT=	Sybase/Microsoft TDS protocol library

WRKSRC=		${WRKDIR}/freetds-0.82.1.dev.20081111
TDS_VER?=	5.0
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_GONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262:env libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-tdsver=${TDS_VER}
USE_LDCONFIG=	yes

PORTDOCS=	*

MAN1=		datacopy.1 freebcp.1 tsql.1 bsqldb.1 bsqlodbc.1 \
		defncopy.1 fisql.1 osql.1
MAN5=		freetds.conf.5

OPTIONS=	OPENSSL "Use openssl" off       \
		GNUTLS "Use GNUTLS" off \
		IODBC   "Use iodbc (Mutually Exclusive)" off    \
		UNIXODBC "Use unixodbc (Mutually Exclusive)" off        \
		MSDBLIB "MS SQL Server support (breaks databases/sybtcl)" off

CONFLICTS=	freetds-0.64.[0-9]

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}
.endif

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=	selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if defined(WITH_IODBC) || defined(WITH_UNIXODBC)
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

# We cannot use msdblib-style by default, because port databases/sybtcl
# relies on sybase-style dblib
.if defined(WITH_MSDBLIB)
CONFIGURE_ARGS+=	--enable-msdblib
TDS_VER=	7.0
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
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doc ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/etc/freetds
	@${INSTALL_DATA} ${WRKSRC}/interfaces ${PREFIX}/etc/freetds/interfaces.dist
	@${ECHO_CMD} "Sample configuration files have been installed in ${PREFIX}/etc"
	@${ECHO_CMD} "You should edit them and remove the .dist-suffix from their names"

.include <bsd.port.post.mk>
