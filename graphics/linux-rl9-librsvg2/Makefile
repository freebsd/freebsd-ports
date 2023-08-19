PORTNAME=	librsvg2
PORTVERSION=	2.50.7
PORTREVISION=	2
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Parse and render SVG vector graphics (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://live.gnome.org/LibRsvg

# TODO: libpixbufloader-svg.so: libdatrie.so.1: cannot open shared object file: No such file or directory

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	librsvg
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig freetype gdkpixbuf2 libxml2 pango png
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
