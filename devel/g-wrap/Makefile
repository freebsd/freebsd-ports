# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#

PORTNAME=	g-wrap
PORTVERSION=	1.1.11
CATEGORIES=	devel
MASTER_SITES=	http://www.gnucash.org/pub/g-wrap/source/ \
		http://people.freebsd.org/~sobomax/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib
LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	GUILE_LOAD_PATH=${WRKSRC}

.include <bsd.port.mk>
