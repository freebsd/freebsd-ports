PORTNAME=	id3lib
PORTVERSION=	3.8.3.20240114
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for manipulating ID3v1/v1.1 and ID3v2 tags
WWW=		https://github.com/thekhalifa/id3lib \
		https://id3lib.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c11 cpe iconv pkgconfig

CMAKE_OFF=	WITH_DOCS WITH_TESTS
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thekhalifa
GH_TAGNAME=	497fe49

post-install:
	cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
