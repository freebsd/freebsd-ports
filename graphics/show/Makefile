# Created by: roop
# $FreeBSD$

PORTNAME=	show
PORTVERSION=	2.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.ibiblio.org/propaganda/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, flexible, extensible, and bloat-free image viewer for X11

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg	\
		libpng15.so:${PORTSDIR}/graphics/png		\
		libtiff.so:${PORTSDIR}/graphics/tiff	\
		libgif.so:${PORTSDIR}/graphics/giflib	\
		libImlib.so:${PORTSDIR}/graphics/imlib

PLIST_FILES=	bin/show

post-extract:
	@${CP} ${PATCHDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/show ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
