# $FreeBSD$

PORTNAME=	exhale
DISTVERSION=	1.0.5
CATEGORIES=	audio

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	xHE-AAC (Extended HE-AAC) encoder

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/include/License.htm

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	ce3641dcdcf29b123dfc077441c56bd7aba293a3

USE_LDCONFIG=	yes

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
