# New ports collection makefile for:	embryo
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	embryo
PORTVERSION=	0.9.1.007
CATEGORIES=	lang
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A C like scripting language used in parts of the Enlightenment

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
