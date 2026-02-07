PORTNAME=	gdk-pixbuf2
PORTVERSION=	2.42.6
DISTVERSIONSUFFIX=	-6.el9_6
PORTREVISION=	8
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphic library for GTK+ (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://developer.gnome.org/gdk-pixbuf/

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	gdk-pixbuf
USE_LDCONFIG=	yes
USE_LINUX=	gnutls imageformats-libs xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-modules-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
