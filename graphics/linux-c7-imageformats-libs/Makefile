PORTNAME=	imageformats
PORTVERSION=	1
CATEGORIES=	graphics linux
PKGNAMESUFFIX=	-libs
DISTNAME=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for working with image formats (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	BSD3CLAUSE GPLv2+ JASPER LIBPNG ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_JASPER=	JasPer License Version 2.0
LICENSE_FILE_JASPER=	${WRKSRC}/usr/share/doc/jasper-libs-1.900.1/LICENSE
LICENSE_PERMS_JASPER=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_NAME_LIBPNG=	libpng license
LICENSE_FILE_LIBPNG=	${WRKSRC}/usr/share/doc/libpng-1.5.13/LICENSE
LICENSE_PERMS_LIBPNG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	jasper${PKGNAMESUFFIX}-1.900.1-33.el7 \
		jbigkit${PKGNAMESUFFIX}-2.0-11.el7 \
		libjpeg-turbo-1.2.90-8.el7 \
		libmng-1.0.10-14.el7 \
		libpng-1.5.13-8.el7 \
		libtiff-4.0.3-35.el7 \
		libwebp-0.3.0-7.el7

SRC_DISTFILES=	jasper-1.900.1-33.el7${SRC_SUFX}:SOURCE \
		jbigkit-2.0-11.el7${SRC_SUFX}:SOURCE \
		libjpeg-turbo-1.2.90-8.el7${SRC_SUFX}:SOURCE \
		libmng-1.0.10-14.el7${SRC_SUFX}:SOURCE \
		libpng-1.5.13-8.el7${SRC_SUFX}:SOURCE \
		libtiff-4.0.3-35.el7${SRC_SUFX}:SOURCE \
		libwebp-0.3.0-7.el7${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
