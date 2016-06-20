# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.1.0
CATEGORIES=	audio linux
MASTER_SITES=	CENTOS_LINUX

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f10-alsa-lib-[0-9]*

BRANDELF_FILES=	sbin/alsactl usr/bin/aconnect usr/bin/alsamixer usr/bin/amidi usr/bin/aplay usr/bin/aplaymidi usr/bin/arecord usr/bin/arecordmidi usr/bin/aseqdump usr/bin/aseqnet usr/bin/iecset usr/bin/speaker-test  usr/sbin/alsactl
USE_LINUX_APPS=	alsalib alsa-plugins-oss

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	nolib
RPMVERSION=	8.el6

.include <bsd.port.mk>
