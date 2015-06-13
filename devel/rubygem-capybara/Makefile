# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	capybara
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integration testing tool for rack based web applications

LICENSE=	MIT

RUN_DEPENDS=	rubygem-mime-types>=1.16:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-nokogiri>=1.3.3:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rack16>=1.0.0:${PORTSDIR}/www/rubygem-rack16 \
		rubygem-rack-test>=0.5.4:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-xpath>=2.0:${PORTSDIR}/devel/rubygem-xpath

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
