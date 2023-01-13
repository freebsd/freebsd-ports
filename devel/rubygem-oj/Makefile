PORTNAME=	oj
PORTVERSION=	3.13.23
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast JSON parser and serializer
WWW=		https://www.ohler.com/oj/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem
USE_RUBY=	yes

# TODO: find a better way to do this
# Copy all header file, as it is required by rubygem-oj-introspect
post-install:
	cd ${WRKSRC}/ext/oj && ${FIND} * -name "*.h" -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/ext/oj/{}" \;


.include <bsd.port.mk>
