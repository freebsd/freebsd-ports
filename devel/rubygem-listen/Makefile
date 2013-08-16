# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	listen
PORTVERSION=	1.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Listen to file modifications and notify about the changes

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rb-kqueue>=0.2.0:${PORTSDIR}/devel/rubygem-rb-kqueue

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e '14,41 d' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
