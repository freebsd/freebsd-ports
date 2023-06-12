PORTNAME=	libvorbis
PORTVERSION=	1.3.7
DISTVERSIONSUFFIX=	-5.el9
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://xiph.org/vorbis/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libogg
USE_LINUX_RPM=	yes

CPE_VENDOR=	xiph.org

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
