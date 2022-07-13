# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	libsvgtiny
PORTVERSION=	0.1.7
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tiny SVG fremebuffer abstraction library, written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:devel/gperf \
		netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libdom.so:www/libdom \
		libwapcaplet.so:textproc/libwapcaplet

USES=		compiler:c11 gmake pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	include/svgtiny.h \
		lib/libsvgtiny.a \
		libdata/pkgconfig/libsvgtiny.pc

.include <bsd.port.mk>
