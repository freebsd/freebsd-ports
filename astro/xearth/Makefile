# New ports collection makefile for:    xearth
# Date created:         29 October 1994
# Whom:                 piero
#
# $FreeBSD$
#

PORTNAME=	xearth
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	astro geography
MASTER_SITES=	XCONTRIB/applications \
		http://seis.bris.ac.uk/~mexas/ \
		LOCAL/simon

MAINTAINER=	mexas@bristol.ac.uk
COMMENT=	Set the root window to the image of earth

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

USE_XORG=	x11 xext sm ice xt
MAN1=		xearth.1

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xearth
	@${INSTALL_MAN} ${WRKSRC}/xearth.man ${MANPREFIX}/man/man1/xearth.1
# Copy the list of FreeBSD sites & committers locations
.for marker in freebsd.committers.markers freebsd.submitters.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${FILESDIR}/${marker} ${PREFIX}/lib/X11/xearth
.endfor

.include <bsd.port.mk>
