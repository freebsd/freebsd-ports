PORTNAME=	exhale
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1.2
CATEGORIES=	audio

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder
WWW=		https://gitlab.com/ecodis/exhale

LICENSE=	EXHALE
LICENSE_NAME=	exhale Copyright License
LICENSE_FILE=	${WRKSRC}/include/License.htm
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	bin/exhale \
		include/exhaleDecl.h \
		lib/libexhale.so

.include <bsd.port.mk>
