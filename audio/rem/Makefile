PORTNAME=	rem
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	audio devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for real-time audio and video processing
WWW=		https://github.com/baresip

DEPRECATED=	Deprecated, replaced by libre
EXPIRATION_DATE=	2023-10-10

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libre.so:audio/re

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	baresip
CMAKE_ARGS=	-DRE_INCLUDE_DIR:STRING="${LOCALBASE}/include/re"

# FIXME values of the next 3 variables taken from source code Makefile
ABI_MAJOR=	6
ABI_AGE=	12
ABI_REV=	0
PLIST_SUB=	ABI_MAJOR=${ABI_MAJOR}
PLIST_SUB+=	ABI_AGE=${ABI_AGE} \
		ABI_REV=${ABI_REV}

.include <bsd.port.mk>
