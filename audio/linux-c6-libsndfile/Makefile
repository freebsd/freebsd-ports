# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libsndfile
PORTVERSION=	1.0.20
PORTREVISION=	4
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF) (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	5.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	flac libogg libvorbis
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
