# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shoulda-matchers
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Making tests easy on the fingers and eyes

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		shebangfix
SHEBANG_FILES=	script/install_gems_in_all_appraisals \
		script/run_all_tests \
		script/update_gem_in_all_appraisals

.include <bsd.port.mk>
