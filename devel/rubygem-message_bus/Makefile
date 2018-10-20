# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	message_bus
PORTVERSION=	2.1.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Message bus for rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack>=1.1.3:www/rubygem-rack

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	examples/chat/docker_container/update_chat

.include <bsd.port.mk>
