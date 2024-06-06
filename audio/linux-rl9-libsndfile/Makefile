PORTNAME=	libsndfile
PORTVERSION=	1.0.31
DISTVERSIONSUFFIX=	-8.el9
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF) (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://www.mega-nerd.com/libsndfile/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	flac gsm libogg libvorbis
USE_LINUX_RPM=	yes

CPE_VENDOR=	libsndfile_project

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
