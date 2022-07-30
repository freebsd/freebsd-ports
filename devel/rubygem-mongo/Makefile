PORTNAME=	mongo
PORTVERSION=	2.18.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby driver for MongoDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bson>=4.14.1<5.0.0:devel/rubygem-bson

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/mongo_console

post-patch:
	@${RM} ${WRKSRC}/spec/support/ocsp

.include <bsd.port.mk>
