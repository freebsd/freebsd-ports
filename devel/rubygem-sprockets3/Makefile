# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack16>=1.0:${PORTSDIR}/www/rubygem-rack16

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/sprockets

.include <bsd.port.mk>
