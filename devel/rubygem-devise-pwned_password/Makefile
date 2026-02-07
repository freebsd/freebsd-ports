PORTNAME=	devise-pwned_password
PORTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Devise extension that checks user passwords against the PwnedPasswords dataset
WWW=		https://github.com/michaelbanfield/devise-pwned_password

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-devise-rails81>=0:devel/rubygem-devise-rails81 \
		rubygem-pwned>=2.4<3:security/rubygem-pwned

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
