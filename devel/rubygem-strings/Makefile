# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strings
PORTVERSION=	0.1.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Useful functions for transforming strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-strings-ansi>=0.1<1:devel/rubygem-strings-ansi \
		rubygem-unicode-display_width>=1.5<2:devel/rubygem-unicode-display_width \
		rubygem-unicode_utils>=1.4<2:devel/rubygem-unicode_utils

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
