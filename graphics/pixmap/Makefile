# Created by: jmz
# $FreeBSD$

PORTNAME=	pixmap
PORTVERSION=	2.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/applications/pixmap
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pixmap editor based on XPM library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# requires rgb.txt
BUILD_DEPENDS=	showrgb:x11/rgb \
		xrdb:x11/xrdb

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake
USE_XORG=	xpm xbitmaps x11 xaw xmu xt sm ice xext

# Remove bundled X11 headers and use headers from X11 libraries
post-extract:
	${RM} -rf ${WRKSRC}/X11

post-configure:
	@${REINPLACE_CMD} 's| $$(PIXMAPDIR|$$(PIXMAPDIR|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
