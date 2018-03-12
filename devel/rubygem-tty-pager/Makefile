# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-pager
PORTVERSION=	0.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal output paging in cross-platform way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-strings>=0.1.0:devel/rubygem-strings \
		rubygem-tty-screen>=0.6.4:devel/rubygem-tty-screen \
		rubygem-tty-which>=0.3.0:devel/rubygem-tty-which

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
