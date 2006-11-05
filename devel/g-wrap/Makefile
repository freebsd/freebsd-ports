# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#

PORTNAME=	g-wrap
PORTVERSION=	1.3.4
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.gnucash.org/pub/g-wrap/source/ \
		http://people.freebsd.org/~sobomax/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	${LOCALBASE}/share/guile/1.6/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk
RUN_DEPENDS=	${LOCALBASE}/share/guile/1.6/slibcat:${PORTSDIR}/lang/slib-guile

INFO=		g-wrap

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	GW_GLIB_CONFIG="${GLIB_CONFIG}"
MAKE_ENV+=	GUILE_LOAD_PATH=${WRKSRC}

.include <bsd.port.mk>
