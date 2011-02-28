# New ports collection makefile for:	libgee
# Date created:				2010-03-14
# Whom:					Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$
#

PORTNAME=	libgee
PORTVERSION=	0.6.1
CATEGORIES=	devel
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	gobject-introspection>=0.9.0:${PORTSDIR}/devel/gobject-introspection

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
