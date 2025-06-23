PORTNAME=	imageformats
PORTVERSION=	1
CATEGORIES=	graphics linux
PKGNAMESUFFIX=	-libs
DISTNAME=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for working with image formats (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ JASPER LIBPNG ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_JASPER=	JasPer License Version 2.0
LICENSE_FILE_JASPER=	${WRKSRC}/usr/share/licenses/jasper-libs/LICENSE
LICENSE_PERMS_JASPER=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_NAME_LIBPNG=	libpng license
LICENSE_FILE_LIBPNG=	${WRKSRC}/usr/share/licenses/libpng/LICENSE
LICENSE_PERMS_LIBPNG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libjxl
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	jasper${PKGNAMESUFFIX}-2.0.28-3.el9 \
		jbigkit${PKGNAMESUFFIX}-2.1-23.el9 \
		libjpeg-turbo-2.0.90-7.el9 \
		libmng-2.0.3-17.el9 \
		libpng-1.6.37-12.el9 \
		libtiff-4.4.0-13.el9 \
		libwebp-1.2.0-8.el9 \
		openjpeg2-2.4.0-8.el9

SRC_DISTFILES=	jasper-2.0.28-3.el9${SRC_SUFX}:SOURCE \
		jbigkit-2.1-23.el9${SRC_SUFX}:SOURCE \
		libjpeg-turbo-2.0.90-7.el9${SRC_SUFX}:SOURCE \
		libmng-2.0.3-17.el9${SRC_SUFX}:SOURCE \
		libpng-1.6.37-12.el9${SRC_SUFX}:SOURCE \
		libtiff-4.4.0-13.el9${SRC_SUFX}:SOURCE \
		libwebp-1.2.0-8.el9${SRC_SUFX}:SOURCE \
		openjpeg2-2.4.0-8.el9${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
