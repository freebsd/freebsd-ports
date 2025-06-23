PORTNAME=	systemd
PORTVERSION=	252
DISTVERSIONSUFFIX=	-51.el9
PORTREVISION=	9
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing systemd (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/wiki/Software/systemd/

LICENSE=	LGPL21+

USES=		cpe linux:rl9
CPE_VENDOR=	systemd_project
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libs libgcrypt libgpg-error lz4 nss
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

.include <bsd.port.mk>
