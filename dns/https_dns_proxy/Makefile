PORTNAME=	https_dns_proxy
PORTVERSION=	g20231226
CATEGORIES=	dns net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Light-weight DNS-HTTPS, non-caching translation proxy
WWW=		https://github.com/aarond10/https_dns_proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libcurl.so:ftp/curl \
		libev.so:devel/libev

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	aarond10
GH_TAGNAME=	8afbba7

CMAKE_ARGS=	-DSW_VERSION:STRING=2023.12.26-${GH_TAGNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
