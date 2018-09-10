# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-oss
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	1.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	alsalib
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
