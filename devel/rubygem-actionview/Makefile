# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	4.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-builder32>=3.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-rails-dom-testing>=1.0.5:${PORTSDIR}/textproc/rubygem-rails-dom-testing \
		rubygem-rails-html-sanitizer>=1.0.1:${PORTSDIR}/textproc/rubygem-rails-html-sanitizer

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
