# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libelf
PORTVERSION=	0.164
PORTREVISION=	1
CATEGORIES=	devel
LIB_DISTFILES=	elfutils-libelf-${DISTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	elfutils-${DISTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ELF file handling library (CentOS ${LINUX_DIST_VER})

DOCSDIR=	${PREFIX}/usr/share/doc/elfutils-libelf-${PORTVERSION}
RPMVERSION=	2.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
