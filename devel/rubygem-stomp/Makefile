PORTNAME=	stomp
PORTVERSION=	1.4.10
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Streaming Text Orientated Messaging Protocol gem
WWW=		https://github.com/stompgem/stomp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/catstomp bin/stompcat

SHEBANG_FILES=	examples/*.sh test/*.sh

.include <bsd.port.mk>
