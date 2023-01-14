PORTNAME=	strings
PORTVERSION=	0.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Useful functions for transforming strings
WWW=		https://github.com/piotrmurach/strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-strings-ansi>=0.2<1:devel/rubygem-strings-ansi \
		rubygem-unicode-display_width>=1.5<3.0:devel/rubygem-unicode-display_width \
		rubygem-unicode_utils>=1.4<2:devel/rubygem-unicode_utils

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
