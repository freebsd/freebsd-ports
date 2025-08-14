PORTNAME=	gitlab-experiment
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Experiment library for Gitlab
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-experiment

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport-gitlab>=3.0:devel/rubygem-activesupport-gitlab \
		rubygem-request_store>=1.0:devel/rubygem-request_store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
