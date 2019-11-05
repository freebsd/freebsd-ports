# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	qiv
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://spiegl.de/qiv/download/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Small, fast GDK/Imlib2 image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		liblcms2.so:graphics/lcms2 \
		libexif.so:graphics/libexif

USES=		gmake gnome pkgconfig tar:tgz xorg
USE_GNOME=	gtk20

PLIST_FILES=	bin/qiv man/man1/qiv.1.gz
USE_XORG+=	x11

do-configure:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|; \
		s|gcc|${CC}|; \
		s|-O2|${CFLAGS}|; \
		s|libs-gdk`|libs-gdk` ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
