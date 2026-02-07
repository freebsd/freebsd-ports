PORTNAME=	picojson
DISTVERSION=	1.3.1.20210117
CATEGORIES=	devel

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Header file only JSON parser/serializer in C++
WWW=		https://github.com/kazuho/picojson

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	kazuho
GH_TAGNAME=	288074e

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
