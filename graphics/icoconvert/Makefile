# New ports collection makefile for:	icoconvert
# Date created:				Apr 30 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	icoconvert
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.mox.net/downloads/ \
		http://www.xunix.org/~flz/distfiles/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A small utility to convert Windows icon files into .xpm and .png files

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_REINPLACE=	yes

PLIST_FILES=	bin/icoconvert

post-patch:
	${REINPLACE_CMD} -e 's|^icoconvert|all|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^\(FLAGS=\)|\1-I${PREFIX}/include |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icoconvert ${PREFIX}/bin

.include <bsd.port.mk>
