PORTNAME=	nspr
PORTVERSION=	4.35.0
DISTVERSIONSUFFIX=	-7.el9_4
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://developer.mozilla.org/docs/Mozilla/Projects/NSPR

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	nss-3.90.0-7.el9_4${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
