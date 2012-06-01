# New ports collection makefile for:	libnotify
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/devel/libnotify/Makefile,v 1.21 2011/06/11 19:51:15 mezz Exp $
#

PORTNAME=	libnotify
PORTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for desktop notifications

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack glib20 gtk20 ltverhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
