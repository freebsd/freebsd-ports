PORTNAME=	highway
PORTVERSION=	1.2.0
DISTVERSIONSUFFIX=	-7.el9
PORTREVISION=	1
MASTER_SITES=	EPEL9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Performance-portable, length-agnostic SIMD with runtime dispatch (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/google/highway

LICENSE=	APACHE20

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
