# Created by: ijliao
# $FreeBSD$

PORTNAME=	scruffy
PORTVERSION=	0.2.6
PORTREVISION=	2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Beautiful Graphs for Ruby

LICENSE=	MIT

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

post-patch:
	@${REINPLACE_CMD} -e 's|#{options|0 0 #{options|' ${WRKSRC}/lib/scruffy/renderers/base.rb

.include <bsd.port.mk>
