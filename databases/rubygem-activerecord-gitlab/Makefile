PORTNAME=	activerecord
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/activerecord \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel-gitlab>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-timeout>=0.4.0:devel/rubygem-timeout

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
