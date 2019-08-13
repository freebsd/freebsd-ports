# $FreeBSD$

PORTNAME=	cms_scanner
PORTVERSION=	0.5.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Framework to provide an easy way to implement CMS Scanners

LICENSE=	MIT

RUN_DEPENDS=	rubygem-nokogiri>=1.10.0<1.11:textproc/rubygem-nokogiri \
		rubygem-opt_parse_validator>=1.7.4<1.8:devel/rubygem-opt_parse_validator \
		rubygem-public_suffix>=3.0<4.1:dns/rubygem-public_suffix \
		rubygem-ruby-progressbar>=1.10.0<1.11:devel/rubygem-ruby-progressbar \
		rubygem-typhoeus>=1.3.0<1.4:www/rubygem-typhoeus \
		rubygem-xmlrpc>=0.3<1:net/rubygem-xmlrpc \
		rubygem-yajl-ruby>=1.4.1<1.5:devel/rubygem-yajl-ruby

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
