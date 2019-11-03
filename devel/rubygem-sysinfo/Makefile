# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysinfo
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All your system-independent infoz in one handy class

LICENSE=	MIT

RUN_DEPENDS=	rubygem-drydock>=0:devel/rubygem-drydock \
		rubygem-storable>=0:devel/rubygem-storable

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/sysinfo

SHEBANG_FILES=	bin/sysinfo

.include <bsd.port.mk>
