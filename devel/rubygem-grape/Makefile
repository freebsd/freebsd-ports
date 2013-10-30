# $FreeBSD$

PORTNAME=	grape
PORTVERSION=	0.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions

RUN_DEPENDS=	rubygem-activesupport>=0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-builder>=0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-hashie>=1.2.0:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-multi_json>=1.3.2:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-multi_xml>=0.5.2:${PORTSDIR}/textproc/rubygem-multi_xml \
		rubygem-rack>=1.3.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-accept>=0:${PORTSDIR}/www/rubygem-rack-accept \
		rubygem-rack-mount>=0:${PORTSDIR}/www/rubygem-rack-mount\
		rubygem-virtus>=0:${PORTSDIR}/devel/rubygem-virtus

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
