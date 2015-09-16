# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdoc
PORTVERSION=	0.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create rdoc html with javascript search index

LICENSE=	MIT

RUN_DEPENDS=	rubygem-json>=1.7.7:${PORTSDIR}/devel/rubygem-json

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sdoc bin/sdoc-merge

.include <bsd.port.mk>
