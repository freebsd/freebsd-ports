# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-table
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fexible and intuitive table generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-equatable>=0.6<1:devel/rubygem-equatable \
		rubygem-necromancer>=0.5<1:devel/rubygem-necromancer \
		rubygem-pastel>=0.7.2<1:devel/rubygem-pastel \
		rubygem-strings>=0.1.5<0.2:devel/rubygem-strings \
		rubygem-tty-screen>=0.7<1:devel/rubygem-tty-screen

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
