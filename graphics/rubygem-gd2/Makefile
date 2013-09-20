# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gd2
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Thomas Boutell's gd 2.x graphics library #'

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

REINPLACE_ARGS=	-i ""

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
post-install:
	@${REINPLACE_CMD} 's|so.2|so.4|' ${PREFIX}/${GEM_LIB_DIR}/lib/gd2.rb

.include <bsd.port.mk>
