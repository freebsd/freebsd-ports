PORTNAME=	exhale
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	1
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
GL_COMMIT=	adef96eace10526b997dc974d960677ab759385b

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	bin/exhale \
		include/exhaleDecl.h \
		lib/libexhale.so

.include <bsd.port.mk>
