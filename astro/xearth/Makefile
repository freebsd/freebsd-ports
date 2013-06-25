# Created by: Piero Serini <piero@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xearth
PORTVERSION=	1.2
CATEGORIES=	astro geography
MASTER_SITES=	http://seis.bris.ac.uk/~mexas/ \
		LOCAL/madpilot/xearth

MAINTAINER=	mexas@bristol.ac.uk
COMMENT=	Set the root window to the image of earth

USE_XORG=	x11 xext sm ice xt
USE_XZ=		yes
MAN1=		xearth.1
PLIST_FILES=	bin/xearth \
		lib/X11/xearth/freebsd.committers.markers \
		lib/X11/xearth/freebsd.ftp.markers
PLIST_DIRS=	lib/X11/xearth

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xearth ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xearth.man ${MANPREFIX}/man/man1/xearth.1
	@${MKDIR} ${PREFIX}/lib/X11/xearth
# Copy the list of FreeBSD sites & committers locations
.for marker in freebsd.committers.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${FILESDIR}/${marker} ${PREFIX}/lib/X11/xearth
.endfor

.include <bsd.port.mk>
