# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#

PORTNAME=	g-wrap
PORTVERSION=	1.3.4
PORTREVISION=	6
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.gnucash.org/pub/g-wrap/source/ \
		http://people.freebsd.org/~sobomax/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	${LOCALBASE}/share/guile/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk
RUN_DEPENDS=	${BUILD_DEPENDS}

INFO=		g-wrap

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	GW_GLIB_CONFIG="${GLIB_CONFIG}"
MAKE_ENV+=	GUILE_LOAD_PATH=${WRKSRC}

.include <bsd.port.mk>
