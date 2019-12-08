# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-prompt
PORTVERSION=	0.20.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Beautiful and powerful interactive command line prompt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-necromancer>=0.5.0<0.6:devel/rubygem-necromancer \
		rubygem-pastel>=0.7.0<0.8:devel/rubygem-pastel \
		rubygem-tty-reader>=0.7.0<0.8:devel/rubygem-tty-reader

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
