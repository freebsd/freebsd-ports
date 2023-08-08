PORTNAME=	libsndfile
PORTVERSION=	1.0.25
DISTVERSIONSUFFIX=	-12.el7_9.1
PORTREVISION=	7
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF) (Linux CentOS ${LINUX_DIST_VER})
WWW=		http://www.mega-nerd.com/libsndfile/

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	flac gsm libogg libvorbis
USE_LINUX_RPM=	yes

CPE_VENDOR=	libsndfile_project

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
