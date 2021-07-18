PORTNAME=	exhale
DISTVERSION=	1.1.6
CATEGORIES=	audio

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder

LICENSE=	EXHALE
LICENSE_NAME=	exhale Copyright License
LICENSE_FILE=	${WRKSRC}/include/License.htm
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	b11042a0f080ab5b0baa98644faabafb3d4b0b95

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
