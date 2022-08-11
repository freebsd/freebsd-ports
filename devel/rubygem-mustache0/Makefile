PORTNAME=	mustache
PORTVERSION=	0.99.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework-agnostic way to render logic-free views

LICENSE=	MIT

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/mustache${PKGNAMESUFFIX}

post-install:
	@${MV} ${STAGEDIR}/${PREFIX}/bin/mustache \
	       ${STAGEDIR}/${PREFIX}/bin/mustache${PKGNAMESUFFIX}

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
