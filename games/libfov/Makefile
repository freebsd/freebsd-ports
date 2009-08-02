# New ports collection makefile for:    libfov
# Date created:         12 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libfov
PORTVERSION=	1.0.3
CATEGORIES=	games devel
MASTER_SITES=	http://libfov.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for calculating fields of view on low resolution rasters

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	ac_cv_prog_doxygen=no ac_cv_path_SDL_CONFIG=no
USE_LDCONFIG=	yes

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^AM_CFLAGS|#AM_CFLAGS|g'

.include <bsd.port.mk>
