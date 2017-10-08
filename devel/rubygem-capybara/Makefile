# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	capybara
PORTVERSION=	2.15.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integration testing tool for rack based web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-mini_mime>=0.1.3:mail/rubygem-mini_mime \
		rubygem-nokogiri>=1.3.3:textproc/rubygem-nokogiri \
		rubygem-rack>=1.0.0:www/rubygem-rack \
		rubygem-rack-test>=0.5.4:www/rubygem-rack-test \
		rubygem-xpath>=2.0:devel/rubygem-xpath

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
