PORTNAME=	clpeak
DISTVERSION=	1.1.4
CATEGORIES=	benchmarks

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Benchmarking tool to measure peak capabilities of opencl devices
WWW=		https://github.com/krrishnarraj/clpeak

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	krrishnarraj
USE_LDCONFIG=	yes
PLIST_FILES=	bin/clpeak

post-patch:
	@${REINPLACE_CMD} '/install.*LICENSE/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
