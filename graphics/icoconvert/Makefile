# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	icoconvert
PORTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.mox.net/downloads/ \
		http://www.xunix.org/~flz/distfiles/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Small utility to convert Windows icon files into .xpm and .png files

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	bin/icoconvert

post-patch:
	@${REINPLACE_CMD} -e 's|^icoconvert|all|' -e 's|^\(FLAGS=\)|\1-I${LOCALBASE}/include |' \
		-e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icoconvert ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
