# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	libfov
PORTVERSION=	1.0.4
CATEGORIES=	games devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for calculating fields of view on low resolution rasters

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_prog_doxygen=no ac_cv_path_SDL_CONFIG=no
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|=.*|= fov|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|#AM_CFLAGS|' \
		${WRKSRC}/fov/Makefile.in

.include <bsd.port.mk>
