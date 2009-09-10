# Ports collection makefile for:	rubygem-warbler
# Date created:				23 July 2008
# Whom:					Alexander Logvinov <ports@logvinov,com>
#
# $FreeBSD$

PORTNAME=	warbler
PORTVERSION=	0.9.14
CATEGORIES=	devel rubygems java
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	caldersphere

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A constructor of .war files of Rails applications

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/warble

.include <bsd.port.mk>
