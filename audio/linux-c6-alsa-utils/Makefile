# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.1.0
DISTVERSIONSUFFIX=	-10.el6
PORTREVISION=	4
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture utilities (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		linux:c6
USE_LINUX=	alsalib alsa-plugins-oss
USE_LINUX_RPM=	nolib

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
