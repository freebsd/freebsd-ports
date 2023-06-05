PORTNAME=	oj
PORTVERSION=	3.15.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast JSON parser and serializer
WWW=		https://www.ohler.com/oj/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

# TODO: find a better way to do this
# Install all header files, some of them are required by devel/rubygem-oj-introspect
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/oj
	${INSTALL_DATA} ${WRKSRC}/ext/oj/*.h ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/oj/

.include <bsd.port.mk>
