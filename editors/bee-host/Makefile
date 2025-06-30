PORTNAME=	bee-host
DISTVERSION=	1.4.0
CATEGORIES=	editors www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Host application for Browser's Exernal Editor extension
WWW=		https://github.com/rosmanov/bee-host

LICENSE=	MIT

LIB_DEPENDS=	libuv.so:devel/libuv	\
		libcjson.so:devel/libcjson

USE_GITHUB=	yes
GH_ACCOUNT=	rosmanov

USES=		cmake:noninja localbase:ldflags shebangfix
SHEBANG_GLOB=	*.sh
LDFLAGS+=	-lcjson -lcjson_utils -luv
CMAKE_ARGS=	-DCMAKE_DOC_DIR:PATH=${DOCSDIR_REL}

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE:C|/||}|' ${WRKSRC}/vars.sh

.include <bsd.port.mk>
