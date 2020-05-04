# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	png2html
PORTVERSION=	1.1
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Takes a PNG image and transforms it into HTML

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png \
		libgd.so:graphics/gd

PLIST_FILES=	bin/png2html

post-patch:
	@${REINPLACE_CMD} 's|CHANGE_ME|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png2html ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
