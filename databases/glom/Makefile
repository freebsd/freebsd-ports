# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.18 2008/03/20 09:26:48 kwm Exp $
#

PORTNAME=	glom
PORTVERSION=	1.6.10
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

LIB_DEPENDS=	bakery-2.4:${PORTSDIR}/x11-toolkits/bakery \
		gdamm-3.0.10:${PORTSDIR}/databases/libgdamm \
		gtksourceviewmm-1.0.1:${PORTSDIR}/x11-toolkits/libgtksourceviewmm \
		goocanvas.3:${PORTSDIR}/graphics/goocanvas
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-3.0.pc:${PORTSDIR}/databases/libgda3-postgresql
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-3.0.pc:${PORTSDIR}/databases/libgda3-postgresql

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix pygnomeextras
USE_LDCONFIG=	yes
USE_PGSQL=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin
INSTALLS_ICONS=	yes

OPTIONS=	SELF_HOSTING "Host the database locally" off

.include <bsd.port.pre.mk>

.if defined(WITH_SELF_HOSTING)
# Note: USE_PGSQL has already been set above.
BUILD_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
.else
CONFIGURE_ARGS+=--enable-client-only
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' \
		${WRKSRC}/Makefile.in

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
