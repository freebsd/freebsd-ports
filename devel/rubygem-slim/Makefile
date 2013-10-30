# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	2.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Template language whose goal is reduce the syntax to essential parts

RUN_DEPENDS=	rubygem-tilt>=1.3.3:${PORTSDIR}/devel/rubygem-tilt \
		rubygem-temple>=0.6.6:${PORTSDIR}/devel/rubygem-temple

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/slimrb


.include <bsd.port.mk>
