PORTNAME=	cookstyle
PORTVERSION=	9.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code linting tool
WWW=		https://docs.chef.io/workstation/cookstyle/ \
		https://github.com/chef/cookstyle

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rubocop>=1.90.0:devel/rubygem-rubocop

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cookstyle

.include <bsd.port.mk>
