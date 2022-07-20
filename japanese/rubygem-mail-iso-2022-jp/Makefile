PORTNAME=	mail-iso-2022-jp
PORTVERSION=	2.0.9
CATEGORIES=	japanese mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides 'mail' gem with iso-2022-jp conversion capability

LICENSE=	MIT

RUN_DEPENDS=	rubygem-mail>=2.2.6,2<2.7.2,2:mail/rubygem-mail

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}rubygem-

.include <bsd.port.post.mk>
