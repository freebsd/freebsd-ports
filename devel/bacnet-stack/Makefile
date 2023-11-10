PORTNAME=	bacnet-stack
PORTVERSION=	1.3.1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	open source protocol stack for embedded systems
WWW=		https://github.com/bacnet-stack/bacnet-stack

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license/readme.txt

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	bacnet-stack
GH_TAGNAME=	934761d

LDFLAGS=	-lm

.include <bsd.port.mk>
