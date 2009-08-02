# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda3/Makefile,v 1.11 2008/03/01 02:35:38 mezz Exp $
#

PORTNAME=	libgda3
PORTVERSION?=	3.0.4
PORTREVISION?=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:R}
DISTNAME=	libgda-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources

USE_BZIP2=	yes
LIBGDA3_SLAVE?=	no

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack glib20 libxslt intlhack referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-bdb --without-sybase
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.pre.mk>

.if ${LIBGDA3_SLAVE}=="no"
MAN1=		gda-config-tool-3.0.1
MAN5=		gda-config-3.0.5
.else
USE_GNOME+=	libgda3
.endif

PLIST_SUB=	VERSION=${PORTVERSION:R}

.if ${LIBGDA3_SLAVE}=="mysql"
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA3_SLAVE}=="postgresql"
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if ${LIBGDA3_SLAVE}=="ldap"
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${LIBGDA3_SLAVE}=="firebird"
LIB_DEPENDS+=		gds.2:${PORTSDIR}/databases/firebird20-client
CONFIGURE_ARGS+=	--with-firebird=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-firebird
.endif

.if ${LIBGDA3_SLAVE}=="freetds"
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

LIB_DEPENDS+=		tds.5:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-tds=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-tds
.endif

.if ${LIBGDA3_SLAVE}=="mdb"
LIB_DEPENDS+=		mdbsql.0:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mdb
.endif

.if ${LIBGDA3_SLAVE}=="odbc"
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/testing//" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure
.for d in fts1.c fts1_porter.c fts1_tokenizer1.c
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/providers/sqlite/sqlite-src/${d}
.endfor
.if ${LIBGDA3_SLAVE}!="no"
. for d in msql firebird odbc freetds mdb ldap mysql sqlite postgres
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/libgda/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/providers/${d}/Makefile.in
. endfor
.endif

.include <bsd.port.post.mk>
.endif
