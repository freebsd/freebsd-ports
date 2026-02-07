PORTNAME=	paper_trail
PORTVERSION=	16.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Track changes to you models
WWW=		https://github.com/paper-trail-gem/paper_trail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord-gitlab>=5<8:databases/rubygem-activerecord-gitlab \
		rubygem-request_store>=1.4<2:devel/rubygem-request_store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
