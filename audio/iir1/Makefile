PORTNAME=	iir1
DISTVERSION=	1.10.0
CATEGORIES=	audio

MAINTAINER=	makc@FreeBSD.org
COMMENT=	DSP IIR Realtime C++ filter library
WWW=		https://github.com/berndporr/iir1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	berndporr
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
