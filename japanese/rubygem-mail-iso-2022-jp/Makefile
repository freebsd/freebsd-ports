PORTNAME=	mail-iso-2022-jp
PORTVERSION=	2.1.0
CATEGORIES=	japanese mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides 'mail' gem with iso-2022-jp conversion capability
WWW=		https://github.com/kuroda/mail-iso-2022-jp

LICENSE=	MIT

RUN_DEPENDS=	rubygem-mail>=2.6.1,2<2.8.1_99,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}rubygem-

.include <bsd.port.post.mk>
