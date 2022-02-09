PORTNAME=	glbinding
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ binding for the OpenGL API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		core gui widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cginternals

LDFLAGS+=	-lpthread # workaround for https://github.com/cginternals/glbinding/issues/327

post-install: # workaround for https://github.com/cginternals/glbinding/issues/328
	@${RM} ${STAGEDIR}${PREFIX}/include/KHR/khrplatform.h
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/KHR

.include <bsd.port.mk>
