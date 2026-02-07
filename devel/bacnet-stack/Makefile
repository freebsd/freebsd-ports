PORTNAME=	bacnet-stack
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	open source protocol stack for embedded systems
WWW=		https://github.com/bacnet-stack/bacnet-stack

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license/readme.txt

LIB_DEPENDS=	libdispatch.so:devel/libdispatch

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	bacnet-stack
GH_TAGNAME=	c111154

LDFLAGS=	-lm

.include <bsd.port.mk>
