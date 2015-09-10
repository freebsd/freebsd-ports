# $FreeBSD$

PORTNAME=	aws-sdk-v1
PORTVERSION=	1.60.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	AWS SDK for Ruby V1

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-nokogiri>=1.4.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-json>=1.4:${PORTSDIR}/devel/rubygem-json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/aws-rb

.include <bsd.port.mk>
