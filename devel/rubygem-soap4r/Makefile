# $FreeBSD$

PORTNAME=	soap4r
PORTVERSION=	1.5.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby implementation of SOAP 1.1

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-httpclient>=2.1.1:${PORTSDIR}/www/rubygem-httpclient

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/wsdl2ruby.rb bin/xsd2ruby.rb

.include <bsd.port.mk>
