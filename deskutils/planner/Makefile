# New ports collection makefile for:	Planner
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	planner
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.11
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for Gnome 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui libgsf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--enable-postgres
PLIST_SUB+=		POSTGRESQL:=""
.else
CONFIGURE_ARGS+=	--disable-postgres
PLIST_SUB+=		POSTGRESQL:="@comment "
.endif

.include <bsd.port.mk>
