# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.91
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.91
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	Diagram creation program, similar to Visio

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-gnome --enable-bonobo
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		dia.1

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--with-python
PLIST_SUB=	PYTHON:=""
.else
PLIST_SUB=	PYTHON:="@comment "
.endif

.include <bsd.port.mk>
