# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	2.10.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-hike>=1.2:${PORTSDIR}/devel/rubygem-hike \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack>=1.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-tilt>=1.1:${PORTSDIR}/devel/rubygem-tilt

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sprockets

post-patch:
	@${REINPLACE_CMD} -e '73 s|~>|">="|; 80,87 d' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
