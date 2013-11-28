# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger-xml
PORTVERSION=	0.3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	XML interface for rubygem-debugger

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=2.0.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-debugger>=1.6.2:${PORTSDIR}/devel/rubygem-debugger

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug-ide bin/rdebug-vim

.include <bsd.port.mk>
