PORTNAME=	libthai
PORTVERSION=	0.1.28
DISTVERSIONSUFFIX=	-8.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Thai language support library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://linux.thai.net/projects/libthai/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
