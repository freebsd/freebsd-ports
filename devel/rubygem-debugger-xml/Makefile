# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger-xml
PORTVERSION=	0.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML interface for rubygem-debugger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-builder32>=2.0.0:devel/rubygem-builder32 \
		rubygem-byebug>=0:devel/rubygem-byebug

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rdebug-ide bin/rdebug-vim

.include <bsd.port.mk>
