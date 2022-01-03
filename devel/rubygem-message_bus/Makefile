# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	message_bus
PORTVERSION=	3.3.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Message bus for rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack>=1.1.3:www/rubygem-rack

USES=		cpe gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	discourse

SHEBANG_FILES=	examples/chat/docker_container/update_chat

.include <bsd.port.mk>
