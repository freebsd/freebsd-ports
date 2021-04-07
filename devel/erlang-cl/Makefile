PORTNAME=	cl
PORTVERSION=	1.2.4
DISTVERSIONPREFIX=	cl-
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenCL binding for Erlang

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USES=		gmake erlang:rebar3 localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	tonyrog

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
