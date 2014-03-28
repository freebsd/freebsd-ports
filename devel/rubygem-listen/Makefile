# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	listen
PORTVERSION=	2.7.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Listen to file modifications and notify about the changes

LICENSE=	MIT

RUN_DEPENDS=	rubygem-celluloid>=0.15.2:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-celluloid-io>=0.15:${PORTSDIR}/devel/rubygem-celluloid-io

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/listen

post-patch:
	@${REINPLACE_CMD} -e '41,68 d' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
