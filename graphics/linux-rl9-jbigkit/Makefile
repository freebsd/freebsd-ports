PORTNAME=	jbigkit
PORTVERSION=	2.1
DISTVERSIONSUFFIX=	-23.el9
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lossless compression for bi-level images (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.cl.cam.ac.uk/~mgk25/jbigkit/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
