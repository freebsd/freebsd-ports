# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog
PORTVERSION=	1.23.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby cloud services library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-fog-brightbox>=0:${PORTSDIR}/devel/rubygem-fog-brightbox \
		rubygem-fog-core>=1.23:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-json>=0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-fog-softlayer>=0:${PORTSDIR}/net/rubygem-fog-softlayer \
		rubygem-ipaddress>=0.5:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-nokogiri>=1.5:${PORTSDIR}/textproc/rubygem-nokogiri

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/fog

.include <bsd.port.mk>
