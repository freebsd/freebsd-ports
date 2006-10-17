# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#    $MCom: ports/devel/g-wrap/Makefile,v 1.4 2006/09/12 21:27:18 ahze Exp $

PORTNAME=	g-wrap
PORTVERSION=	1.3.4
PORTEPOCH=	1
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.gnucash.org/pub/g-wrap/source/ \
		http://people.freebsd.org/~sobomax/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	slib-guile>0:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile
RUN_DEPENDS=	slib-guile>0:${PORTSDIR}/lang/slib-guile

INFO=		g-wrap

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	GW_GLIB_CONFIG="${TRUE}" \
		CPPFLAGS="`${LOCALBASE}/bin/pkg-config --cflags glib-2.0`" \
		LIBS="`${LOCALBASE}/bin/pkg-config --libs glib-2.0`"
MAKE_ENV+=	GUILE_LOAD_PATH=${WRKSRC}

.include <bsd.port.mk>
