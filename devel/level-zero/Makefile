# $FreeBSD$

PORTNAME=	level-zero
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	oneAPI Level Zero Specification Headers and Loader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	oneapi-src

post-extract:
	@${ECHO_CMD} ${DISTVERSION:E} >${WRKSRC}/VERSION_PATCH

.include <bsd.port.mk>
