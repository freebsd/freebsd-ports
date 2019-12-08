# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-reader
PORTVERSION=	0.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Methods for processing keyboard input

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-tty-cursor>=0.7<1:devel/rubygem-tty-cursor \
		rubygem-tty-screen>=0.7<1:devel/rubygem-tty-screen \
		rubygem-wisper>=2.0.0<2.1:devel/rubygem-wisper

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
