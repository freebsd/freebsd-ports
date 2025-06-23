PORTNAME=	elfutils
PORTVERSION=	0.192
DISTVERSIONSUFFIX=	-5.el9
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
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL} \
		${PORTNAME}-debuginfod-client-${DISTVERSIONFULL}

PLIST_SUB=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
