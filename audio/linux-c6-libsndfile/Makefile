# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libsndfile
PORTVERSION=	1.0.20
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF) (Linux CentOS ${LINUX_DIST_VER})

CONTFLICTS=	linux-libsndfile-[0-9]* linux-f10-libsndfile-[0-9]*

USE_LINUX=	c6
USE_LINUX_APPS=	flac libogg libvorbis
USE_LINUX_RPM=	yes

RPMVERSION=	5.el6
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
