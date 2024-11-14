PORTNAME=	graphene
PORTVERSION=	1.10.6
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Optimizations for speeding up vector operations (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://ebassi.github.io/graphene/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
