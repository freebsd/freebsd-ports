PORTNAME=	exhale
DISTVERSION=	1.2.0
CATEGORIES=	audio

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder
WWW=		https://gitlab.com/ecodis/exhale

LICENSE=	EXHALE
LICENSE_NAME=	exhale Copyright License
LICENSE_FILE=	${WRKSRC}/include/License.htm
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	cfbcd5b7cc488d84fb01fa9699586d89c8c4b320

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	bin/exhale \
		include/exhaleDecl.h \
		lib/libexhale.so

.include <bsd.port.mk>
