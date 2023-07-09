PORTNAME=	message_bus
PORTVERSION=	4.3.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Message bus for rack
WWW=		https://github.com/discourse/message_bus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack>=1.1.3,3:www/rubygem-rack

USES=		cpe gem shebangfix

NO_ARCH=	yes

CPE_VENDOR=	discourse

SHEBANG_FILES=	examples/chat/docker_container/update_chat

.include <bsd.port.mk>
