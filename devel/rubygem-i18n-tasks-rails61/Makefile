PORTNAME=	i18n-tasks
PORTVERSION=	1.0.12
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	i18n-tasks helps managing missing and unused translation
WWW=		https://github.com/glebm/i18n-tasks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport61>=4.0.2:devel/rubygem-activesupport61 \
		rubygem-ast>=2.1.0:devel/rubygem-ast \
		rubygem-better_html-rails61>=1.0<3.0:devel/rubygem-better_html-rails61 \
		rubygem-erubi>0:www/rubygem-erubi \
		rubygem-highline>=2.0.0:devel/rubygem-highline \
		rubygem-i18n>0:devel/rubygem-i18n \
		rubygem-parser>=2.2.3.0:devel/rubygem-parser \
		rubygem-rails-i18n-rails61>0:devel/rubygem-rails-i18n-rails61 \
		rubygem-rainbow>=2.2.2<4.0:devel/rubygem-rainbow \
		rubygem-terminal-table>=1.5.1:textproc/rubygem-terminal-table

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/i18n-tasks

.include <bsd.port.mk>
