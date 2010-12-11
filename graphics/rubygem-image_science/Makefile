# Ports collection makefile for:	rubygem-image_science
# Date created:				5 Dec 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	image_science
PORTVERSION=	1.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Ruby library that generates thumbnails

RUN_DEPENDS=	rubygem-hoe>=2.3.3:${PORTSDIR}/devel/rubygem-hoe \
		freeimage>=3.12.0:${PORTSDIR}/graphics/freeimage \
 		rubygem-inline>=3.8.5:${PORTSDIR}/devel/rubygem-inline

LICENSE=		MIT

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/image_science_thumb

.include <bsd.port.mk>
