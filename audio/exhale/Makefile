# $FreeBSD$

PORTNAME=	exhale
DISTVERSION=	1.1.1
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
GL_COMMIT=	36964d2051150ae702a6eb043f5c527f9e094985

USE_LDCONFIG=	yes

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
