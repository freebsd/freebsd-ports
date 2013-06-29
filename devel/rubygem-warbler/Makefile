# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	warbler
PORTVERSION=	1.3.8
CATEGORIES=	devel rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A constructor of .war files of Rails applications

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby \
		rubygem-jruby-jars>=1.5.6:${PORTSDIR}/devel/rubygem-jruby-jars \
		rubygem-jruby-rack>=1.0.0:${PORTSDIR}/www/rubygem-jruby-rack \
		rubygem-rubyzip>=0.9.8:${PORTSDIR}/archivers/rubygem-rubyzip

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/warble

.include <bsd.port.mk>
