PORTNAME=	alsa-utils
PORTVERSION=	1.1.8
DISTVERSIONSUFFIX=	-2.el7
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture utilities (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.alsa-project.org/

LICENSE=	GPLv3

USES=		linux:c7
USE_LINUX=	alsalib alsa-plugins-oss
USE_LINUX_RPM=	nolib

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
# This binary needs libsamplerate.so, which we do not package
	${RM} ${STAGEDIR}${PREFIX}/usr/bin/alsaloop

.include <bsd.port.mk>
