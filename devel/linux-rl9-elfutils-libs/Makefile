PORTNAME=	elfutils
PORTVERSION=	0.189
DISTVERSIONSUFFIX=	-3.el9
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ELF file handling libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://sourceware.org/elfutils/

USES=		cpe linux:rl9
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libelf
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

.include <bsd.port.mk>
