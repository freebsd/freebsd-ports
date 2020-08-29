# $FreeBSD$

PORTNAME=	librsvg2
PORTVERSION=	2.40.20
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Parse and render SVG vector graphics (CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig freetype gdkpixbuf2 libcroco libxml2 pango png
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
