PORTNAME=	libevent
PORTVERSION=	2.1.13
DISTVERSIONSUFFIX=	-1.el9_8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://libevent.org/

LICENSE=	BSD3CLAUSE

USES=		cpe linux:rl9
CPE_VENDOR=	libevent_project
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
