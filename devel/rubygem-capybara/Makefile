# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	capybara
PORTVERSION=	3.32.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integration testing tool for rack based web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-mini_mime>=0.1.3:mail/rubygem-mini_mime \
		rubygem-nokogiri>=1.8<2:textproc/rubygem-nokogiri \
		rubygem-rack>=1.6.0:www/rubygem-rack \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-regexp_parser>=1.5<2:textproc/rubygem-regexp_parser \
		rubygem-xpath>=3.2<4:devel/rubygem-xpath

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
