# New ports collection makefile for:	embryo
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	embryo
PORTVERSION=	0.9.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A C like scripting language used in parts of the Enlightenment

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
