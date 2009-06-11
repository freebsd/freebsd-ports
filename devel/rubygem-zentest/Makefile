# Ports collection makefile for:	rubygem-zentest
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zentest
PORTVERSION=	4.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
DISTNAME=	ZenTest-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby Unit Testing Utility

BUILD_DEPENDS=	rubygem-hoe>=1.5.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/autotest \
		bin/multigem \
		bin/multiruby \
		bin/multiruby_setup \
		bin/unit_diff \
		bin/zentest

.include <bsd.port.mk>
