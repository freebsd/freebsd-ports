# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysinfo
PORTVERSION=	0.8.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All your system-independent infoz in one handy class

LICENSE=	MIT

RUN_DEPENDS=	rubygem-drydock>=0:${PORTSDIR}/devel/rubygem-drydock \
		rubygem-storable>=0:${PORTSDIR}/devel/rubygem-storable

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sysinfo

.include <bsd.port.mk>
