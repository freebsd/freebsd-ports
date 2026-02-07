PORTNAME=	gitlab-security_report_schemas
PORTVERSION=	0.1.3.min15.0.0.max15.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby gem for GitLab security report JSON schemas
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-security_report_schemas

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport-gitlab>=6<8:devel/rubygem-activesupport-gitlab \
		rubygem-json_schemer>=2.3.0<2.4:devel/rubygem-json_schemer \
		rubygem-mutex_m>=0.3.0<0.4:devel/rubygem-mutex_m

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/security-report-schemas

.include <bsd.port.mk>
