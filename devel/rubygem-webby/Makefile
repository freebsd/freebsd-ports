# Created by: Ryan Steinmetz (<rpsfa@rit.edu>)
# $FreeBSD$

PORTNAME=	webby
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Small website management system

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bones>=2.5.0:devel/rubygem-bones \
		rubygem-directory_watcher>=1.1.2:devel/rubygem-directory_watcher \
		rubygem-hpricot>=0.6.0:www/rubygem-hpricot \
		rubygem-launchy>=0.3.2:devel/rubygem-launchy \
		rubygem-logging>=0.9.7:devel/rubygem-logging \
		rubygem-loquacious>=1.3.0:devel/rubygem-loquacious \
		rubygem-rspec>=1.2.2:devel/rubygem-rspec

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/webby bin/webby-gen

.include <bsd.port.mk>
