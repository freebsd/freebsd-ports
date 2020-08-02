# $FreeBSD$

PORTNAME=	exhale
DISTVERSION=	1.0.6
CATEGORIES=	audio

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/include/License.htm

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	c72996090e82b1aad273efde0a8d281f9f0e95a9

USE_LDCONFIG=	yes

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
