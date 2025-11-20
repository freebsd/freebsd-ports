PORTNAME=	activejob
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Declare job classes that can be run by a variety of queuing backends
WWW=		https://github.com/rails/rails/tree/main/activejob \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-globalid-rails-gitlab>=0.3.6:databases/rubygem-globalid-rails-gitlab

USES=		cpe gem

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
