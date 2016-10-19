# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.0.28
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

USE_LINUX=	alsalib alsa-plugins-oss

USES=		linux:c7
USE_LINUX_RPM=	nolib
RPMVERSION=	4.el7

.include <bsd.port.mk>
