# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger-xml
PORTVERSION=	0.1.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	XML interface for rubygem-debugger

RUN_DEPENDS=	rubygem-debugger>=1.6.2:${PORTSDIR}/devel/rubygem-debugger \
		rubygem-builder>=2.0.0:${PORTSDIR}/devel/rubygem-builder

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug-ide bin/rdebug-vim

NO_STAGE=	yes

.include <bsd.port.mk>
