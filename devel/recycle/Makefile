PORTNAME=	recycle
DISTVERSION=	7.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple resource pool for recycling resources in C++
WWW=		https://github.com/steinwurf/recycle

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	steinwurf

PLIST_FILES=	include/recycle/no_locking_policy.hpp \
		include/recycle/shared_pool.hpp \
		include/recycle/unique_pool.hpp

NO_ARCH=	yes

.include <bsd.port.mk>
