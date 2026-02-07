PORTNAME=	librsvg2
PORTVERSION=	2.50.7
DISTVERSIONSUFFIX=	-3.el9
PORTREVISION=	5
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Parse and render SVG vector graphics (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://live.gnome.org/LibRsvg

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	librsvg
USE_LDCONFIG=	yes
USE_LINUX=	cairo cairo-gobject fontconfig freetype gdkpixbuf2 libxml2 \
		pango
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
