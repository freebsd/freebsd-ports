# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stella
PORTVERSION=	2.1.2.004
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Define realistic testplans and run them against your webapps

LICENSE=	MIT

RUN_DEPENDS=	rubygem-benelux>=0.6.1:${PORTSDIR}/devel/rubygem-benelux \
		rubygem-drydock>=0.6.9:${PORTSDIR}/devel/rubygem-drydock \
		rubygem-familia>=0.7.1:${PORTSDIR}/databases/rubygem-familia \
		rubygem-gibbler>=0.8.9:${PORTSDIR}/devel/rubygem-gibbler \
		rubygem-nokogiri>=1.4.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-public_suffix_service>=0.8.1:${PORTSDIR}/dns/rubygem-public_suffix_service \
		rubygem-storable>=0.8.8:${PORTSDIR}/devel/rubygem-storable \
		rubygem-sysinfo>=0.7.3:${PORTSDIR}/devel/rubygem-sysinfo \
		rubygem-whois>=1.6.6:${PORTSDIR}/net/rubygem-whois \
		rubygem-yajl-ruby>=0.7.9:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/stella

.include <bsd.port.mk>
