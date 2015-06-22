# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	listen
PORTVERSION=	2.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Listen to file modifications and notify about the changes

LICENSE=	MIT

RUN_DEPENDS=	rubygem-celluloid>=0.16.0:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-rb-fsevent>=0.9.3:${PORTSDIR}/devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9:${PORTSDIR}/devel/rubygem-rb-inotify \
		rubygem-rb-kqueue>=0.2:${PORTSDIR}/devel/rubygem-rb-kqueue

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/listen

.include <bsd.port.mk>
