# $FreeBSD$

PORTNAME=	systemd
PORTVERSION=	219
DISTVERSIONSUFFIX=	-67.el7_7.4
PORTREVISION=	5
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing systemd (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libs libgcrypt libgpg-error lz4
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

post-patch:
	@${RM} -r ${WRKSRC}/usr/lib*/libudev.so.* ${WRKSRC}/usr/lib*/security

.include <bsd.port.mk>
