PORTNAME=	nspr
PORTVERSION=	4.35.0
DISTVERSIONSUFFIX=	-1.el7_9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://developer.mozilla.org/docs/Mozilla/Projects/NSPR

USES=		cpe linux:c7
CPE_PRODUCT=	netscape_portable_runtime
CPE_VENDOR=	mozilla
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
