# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f10-alsa-lib-[0-9]*

USE_LINUX=	alsalib alsa-plugins-oss

USES=		linux:c6
USE_LINUX_RPM=	nolib
RPMVERSION=	8.el6

.include <bsd.port.mk>
