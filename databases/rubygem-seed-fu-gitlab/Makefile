PORTNAME=	seed-fu
PORTVERSION=	2.3.9
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library to maintain seed data
WWW=		https://github.com/mbleigh/seed-fu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord-gitlab>=3.1:databases/rubygem-activerecord-gitlab \
		rubygem-activesupport-gitlab>=3.1:devel/rubygem-activesupport-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
