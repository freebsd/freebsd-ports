# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stella
PORTVERSION=	2.1.2.004
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Define realistic testplans and run them against your webapps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-benelux>=0.6.1:devel/rubygem-benelux \
		rubygem-drydock>=0.6.9:devel/rubygem-drydock \
		rubygem-familia>=0.7.1:databases/rubygem-familia \
		rubygem-gibbler>=0.8.9:devel/rubygem-gibbler \
		rubygem-nokogiri>=1.4.4:textproc/rubygem-nokogiri \
		rubygem-public_suffix_service>=0.8.1:dns/rubygem-public_suffix_service \
		rubygem-storable>=0.8.8:devel/rubygem-storable \
		rubygem-sysinfo>=0.7.3:devel/rubygem-sysinfo \
		rubygem-whois>=1.6.6:net/rubygem-whois \
		rubygem-yajl-ruby>=0.7.9:devel/rubygem-yajl-ruby

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/stella

SHEBANG_FILES=	bin/stella \
		support/sample_webapp/app.rb

.include <bsd.port.mk>
