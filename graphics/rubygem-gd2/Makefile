# Ports collection makefile for:	rubygem-gd2
# Date created:				07 June 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	gd2
PORTVERSION=	1.1.1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Ruby binding for Thomas Boutell's gd 2.x graphics library #'

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

REINPLACE_ARGS=	-i ""

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${REINPLACE_CMD} 's|so.2|so.4|' ${PREFIX}/${GEM_LIB_DIR}/lib/gd2.rb

.include <bsd.port.mk>
