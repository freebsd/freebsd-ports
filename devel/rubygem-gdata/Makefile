# Ports collection makefile for:	rubygem-gdata
# Date created:				Feb 27, 2009
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gdata
PORTVERSION=	1.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Assist Ruby developers in working with Google Data APIs

BUILD_DEPENDS=	rubygem-rails>=2.2.2:${PORTSDIR}/www/rubygem-rails
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
