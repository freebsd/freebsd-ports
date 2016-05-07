# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	turn
PORTVERSION=	0.9.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	New output format for Test::Unit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ansi>=0:devel/rubygem-ansi \
		rubygem-minitest>=4:devel/rubygem-minitest

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/turn

.include <bsd.port.mk>
