# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	gnmm
PORTVERSION=	0.1.2
PORTREVISION=	12
CATEGORIES=	games gnome
MASTER_SITES=	SF
DIST_SUBDIR=	gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A "nine mens' morris" implementation for the GNOME Desktop Environment

USE_GMAKE=	yes
USES=		pathfix gettext iconv
USE_GNOME=	gnomeprefix gnomelibs gdkpixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"${ICONV_CONFIGURE_ARG}"

.include <bsd.port.mk>
