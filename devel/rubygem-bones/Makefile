# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bones
PORTVERSION=	3.8.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to create new projects from code skeleton

LICENSE=	MIT

RUN_DEPENDS=	rubygem-little-plugger>=1.1:${PORTSDIR}/devel/rubygem-little-plugger \
		rubygem-loquacious>=1.9:${PORTSDIR}/devel/rubygem-loquacious \
		rubygem-rake>=10.0:${PORTSDIR}/devel/rubygem-rake

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bones

.include <bsd.port.mk>
