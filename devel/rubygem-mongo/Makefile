PORTNAME=	mongo
PORTVERSION=	2.19.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby driver for MongoDB
WWW=		https://github.com/mongodb/mongo-ruby-driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bson>=4.14.1<5.0.0:devel/rubygem-bson

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mongo_console

.include <bsd.port.mk>
