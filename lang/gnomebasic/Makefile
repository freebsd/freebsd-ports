# New ports collection makefile for:	gnomebasic
# Date created:				28th June 2000
# Whom:				Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebasic
PORTVERSION=	0.0.17
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gb
DISTNAME=	gb-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
