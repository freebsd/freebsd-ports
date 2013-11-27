# Created by: ijliao
# $FreeBSD$

PORTNAME=	scruffy
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Beautiful Graphs for Ruby

RUN_DEPENDS=	rubygem-builder>=2.0.0:${PORTSDIR}/devel/rubygem-builder

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST= yes

post-install:
	${REINPLACE_CMD} -e 's|#{options|0 0 #{options|' \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/scruffy/renderers/base.rb
	grep options ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/scruffy/renderers/base.rb

.include <bsd.port.mk>
