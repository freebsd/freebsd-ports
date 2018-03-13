# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-prompt
PORTVERSION=	0.16.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Beautiful and powerful interactive command line prompt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-necromancer>=0.4.0:devel/rubygem-necromancer \
		rubygem-pastel>=0.7.0:devel/rubygem-pastel \
		rubygem-timers>=4.0:devel/rubygem-timers \
		rubygem-tty-cursor>=0.5.0:devel/rubygem-tty-cursor \
		rubygem-tty-reader>=0.2.0:devel/rubygem-tty-reader

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
