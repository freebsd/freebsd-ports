# $FreeBSD$

PORTNAME=	exhale
DISTVERSION=	1.0.7
CATEGORIES=	audio

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/include/License.htm

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	54a7bcd78320870f12020bf75489a930731cb308

USE_LDCONFIG=	yes

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
