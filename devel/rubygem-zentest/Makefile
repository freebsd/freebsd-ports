# Ports collection makefile for:	rubygem-zentest
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zentest
PORTVERSION=	3.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
DISTNAME=	ZenTest-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby Unit Testing Utility

BUILD_DEPENDS=	rubygem-hoe>=1.5.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=    ${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
