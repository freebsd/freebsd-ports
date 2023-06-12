PORTNAME=	libasyncns
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	-22.el9
CATEGORIES=	dns devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for executing DNS queries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://0pointer.de/lennart/projects/libasyncns/

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
