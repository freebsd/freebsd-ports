# New ports collection makefile for:	libmrproject
# Date created:				17 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrproject
PORTVERSION=	0.10
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library backend for MrProject project management application

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libgsf libxslt
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-static

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

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
