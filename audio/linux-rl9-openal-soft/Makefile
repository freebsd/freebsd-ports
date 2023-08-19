PORTNAME=	openal-soft
PORTVERSION=	1.19.1
DISTVERSIONSUFFIX=	-16.el9
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	3D positional spatialized sound library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://openal-soft.org/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	alsalib
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
