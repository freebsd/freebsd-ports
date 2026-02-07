PORTNAME=	shoulda
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Making tests easy on the fingers and eyes
WWW=		https://github.com/thoughtbot/shoulda

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-shoulda-context>=2.0<3:devel/rubygem-shoulda-context \
		rubygem-shoulda-matchers>=4.0<5:devel/rubygem-shoulda-matchers

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	script/*

.include <bsd.port.mk>
