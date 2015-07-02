# $FreeBSD$

PORTNAME=	attr_required
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby implementations of attr_required and attr_optional

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	${CHMOD} -R go-w ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/

.include <bsd.port.mk>
