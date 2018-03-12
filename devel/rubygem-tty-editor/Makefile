# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-editor
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opens a file or text in the user preferred editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-tty-prompt>=0.14.0:devel/rubygem-tty-prompt \
		rubygem-tty-which>=0.3.0:devel/rubygem-tty-which

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
