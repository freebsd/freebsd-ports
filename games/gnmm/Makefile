# New ports collection makefile for:	gnmm
# Date created:				19 January 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gnmm
PORTVERSION=	0.1.2
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A "nine mens' morris" implementation for the GNOME Desktop Environment

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-libiconv-prefix=${LOCALBASE}"

.include <bsd.port.mk>
