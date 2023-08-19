PORTNAME=	ocl-icd
PORTVERSION=	2.2.13
DISTVERSIONSUFFIX=	-4.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenCL Installable Client Driver (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/OCL-dev/ocl-icd

LICENSE=	BSD2CLAUSE

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libgcrypt libpsl
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
