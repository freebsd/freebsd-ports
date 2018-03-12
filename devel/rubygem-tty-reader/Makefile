# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-reader
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Methods for processing keyboard input

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-tty-cursor>=0.5.0:devel/rubygem-tty-cursor \
		rubygem-tty-screen>=0.6.4:devel/rubygem-tty-screen \
		rubygem-wisper>=2.0.0:devel/rubygem-wisper

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
