# New ports collection makefile for:   gjs
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/lang/gjs/Makefile,v 1.5 2010/03/20 01:14:31 marcus Exp $
#

PORTNAME=	gjs
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GECKO=	libxul
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	build
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack glib20 ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not link on 6.x
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/scripts/make-tests

.include <bsd.port.post.mk>
