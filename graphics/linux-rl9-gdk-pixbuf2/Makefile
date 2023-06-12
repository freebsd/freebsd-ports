PORTNAME=	gdk-pixbuf2
PORTVERSION=	2.42.6
DISTVERSIONSUFFIX=	-3.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphic library for GTK+ (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://developer.gnome.org/gdk-pixbuf/

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	gdk-pixbuf
USE_LDCONFIG=	yes
USE_LINUX=	jasper jpeg png tiff xorglibs
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
