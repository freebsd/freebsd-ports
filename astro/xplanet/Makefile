# New ports collection makefile for:    xplanet
# Date created:		22 Feb 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	xplanet
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw pictures of the earth textured by an image

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		netpbm.1:${PORTSDIR}/graphics/netpbm

USE_X_PREFIX=	yes
USE_GCC=	3.2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-map-extension=jpg --with-freetype --with-gif \
		--with-png --with-pnm --with-tiff
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm"
USE_GMAKE=	yes

MAN1=	xplanet.1

# Install the list of FreeBSD sites & committers locations from astro/xearth
post-install:
.for file in freebsd.committers.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${PORTSDIR}/astro/xearth/files/${file} \
		${DATADIR}/markers
.endfor

.include <bsd.port.mk>
