PORTNAME=	mongo
PORTVERSION=	2.20.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby driver for MongoDB
WWW=		https://github.com/mongodb/mongo-ruby-driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bson>=4.14.1<6.0.0:devel/rubygem-bson

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mongo_console

post-patch:
	@${TOUCH} ${WRKSRC}/spec/support/ocsp

post-install:
	@${RM} ${STAGEDIR}${PREFIX}${GEM_LIB_DIR}/spec/support/ocsp

.include <bsd.port.mk>
