# Created by: Ryan Steinmetz (<rpsfa@rit.edu>)
# $FreeBSD$

PORTNAME=	webby
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Small website management system

RUN_DEPENDS=	rubygem-bones>=2.5.0:${PORTSDIR}/devel/rubygem-bones \
		rubygem-directory_watcher>=1.1.2:${PORTSDIR}/devel/rubygem-directory_watcher \
		rubygem-hpricot>=0.6.0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-launchy>=0.3.2:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-logging>=0.9.7:${PORTSDIR}/devel/rubygem-logging \
		rubygem-loquacious>=1.3.0:${PORTSDIR}/devel/rubygem-loquacious \
		rubygem-rspec>=1.2.2:${PORTSDIR}/devel/rubygem-rspec

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/webby bin/webby-gen

.include <bsd.port.mk>
