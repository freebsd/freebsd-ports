PORTNAME=	libogg
PORTVERSION=	1.3.4
DISTVERSIONSUFFIX=	-6.el9
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Ogg bitstream library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.xiph.org/ogg/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
