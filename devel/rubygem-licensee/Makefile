# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	licensee
PORTVERSION=	6.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Detects under what license a project is distributed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rugged>=0.23:devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/licensee

.include <bsd.port.mk>
