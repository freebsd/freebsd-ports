# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.1.1
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-oss
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-c6-${LINUXNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	1.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	alsalib
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
