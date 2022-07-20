PORTNAME=	libvorbis
PORTVERSION=	1.3.3
DISTVERSIONSUFFIX=	-8.el7.1
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libogg
USE_LINUX_RPM=	yes

CPE_VENDOR=	xiph.org

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
