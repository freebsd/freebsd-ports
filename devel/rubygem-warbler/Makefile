# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	warbler
PORTVERSION=	2.0.4
CATEGORIES=	devel rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Constructor of .war files of Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	jruby:lang/jruby \
		rubygem-jruby-jars>=9.0.0.0:devel/rubygem-jruby-jars \
		rubygem-jruby-rack>=1.1.1:www/rubygem-jruby-rack \
		rubygem-rake>=10.1.0:devel/rubygem-rake \
		rubygem-rubyzip>=1.0:archivers/rubygem-rubyzip

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/warble

.include <bsd.port.mk>
