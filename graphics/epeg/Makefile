# New ports collection makefile for:	epeg
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	epeg
PORTVERSION=	0.9.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An immensely fast jpeg thumbnailer library API

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
