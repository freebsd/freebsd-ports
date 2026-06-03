PORTNAME=	oj
PORTVERSION=	3.16.16
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Fast JSON parser and serializer
WWW=		https://www.ohler.com/oj/ \
		https://github.com/ohler55/oj

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal-gitlab>=3.0:math/rubygem-bigdecimal-gitlab \
		rubygem-ostruct>=0.2:devel/rubygem-ostruct

USES=		gem

# TODO: find a better way to do this
# Install all header files, some of them are required by devel/rubygem-oj-introspect
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/oj
	${INSTALL_DATA} ${WRKSRC}/ext/oj/*.h ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/oj/

.include <bsd.port.mk>
