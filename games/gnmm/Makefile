# New ports collection makefile for:	gnmm
# Date created:				19 January 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gnmm
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	barner@FreeBSD.org
COMMENT=	A "nine mens' morris" implementation for the GNOME Desktop Environment

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-libiconv-prefix=${LOCALBASE}"

.include <bsd.port.mk>
