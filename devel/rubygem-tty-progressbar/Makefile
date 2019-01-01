# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-progressbar
PORTVERSION=	0.16.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flexible progress bars drawing in terminal emulators

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-strings-ansi>=0.1.0:devel/rubygem-strings-ansi \
		rubygem-tty-cursor>=0.6.0:devel/rubygem-tty-cursor \
		rubygem-tty-screen>=0.6.4:devel/rubygem-tty-screen \
		rubygem-unicode-display_width>=1.3:devel/rubygem-unicode-display_width

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
