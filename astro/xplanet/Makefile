# New ports collection makefile for:    xplanet
# Date created:		22 Feb 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	xplanet
PORTVERSION=	0.94
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		netpbm.1:${PORTSDIR}/graphics/netpbm

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-map-extension=jpg --with-freetype --with-gif \
		--with-png --with-pnm --with-tiff

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm" \
		WISH=${LOCALBASE}/bin/wish8.3

MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm"

MAN1=		xplanet.1 xplanetbg.1 tkxplanet.1 tzcoord.pl.1
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

pre-configure:
	@${PERL} -pi -e 's|-O3||' ${WRKSRC}/configure

pre-build:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/auxfiles.h

# Install the list of FreeBSD sites & committers locations from astro/xearth
post-install:
.for file in freebsd.committers.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${PORTSDIR}/astro/xearth/files/${file} \
		${PREFIX}/share/xplanet/markers
.endfor

.include <bsd.port.post.mk>
