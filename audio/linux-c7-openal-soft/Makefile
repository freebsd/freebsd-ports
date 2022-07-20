PORTNAME=	openal-soft
PORTVERSION=	1.16.0
DISTVERSIONSUFFIX=	-3.el7
PORTREVISION=	3
CATEGORIES=	audio linux
MASTER_SITES=	EPEL7/o \
		https://harbottle.gitlab.io/wine32/7/i386/:i386

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	3D positional spatialized sound library (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	alsalib
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
