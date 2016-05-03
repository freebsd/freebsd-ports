# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	listen
PORTVERSION=	3.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Listen to file modifications and notify about the changes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rb-fsevent>=0.9.3:devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9.7:devel/rubygem-rb-inotify \
		rubygem-rb-kqueue>=0.2:devel/rubygem-rb-kqueue

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/listen

.include <bsd.port.mk>
