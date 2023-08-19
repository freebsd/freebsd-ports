PORTNAME=	libevent
PORTVERSION=	2.1.12
DISTVERSIONSUFFIX=	-6.el9
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://libevent.org/

LICENSE=	BSD3CLAUSE

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
