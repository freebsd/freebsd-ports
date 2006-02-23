# New ports collection makefile for:	eet
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	eet
PORTVERSION=	0.9.10.023
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
