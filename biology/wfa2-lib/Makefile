PORTNAME=		wfa2-lib
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.5
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Exact gap-affine algorithm using homology to accelerate alignment
WWW=		https://github.com/smarco/WFA2-lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	smarco
GH_PROJECT=	WFA2-lib

.if !exists(/usr/include/omp.h)
USES+=	compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
