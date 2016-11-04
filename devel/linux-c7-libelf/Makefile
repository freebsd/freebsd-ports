# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libelf
PORTVERSION=	0.163
CATEGORIES=	devel
LIB_DISTFILES=	elfutils-libelf-${DISTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	elfutils-${DISTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ELF file handling library (CentOS ${LINUX_DIST_VER})

RPMVERSION=	3.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
