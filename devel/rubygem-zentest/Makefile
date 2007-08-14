# Ports collection makefile for:	rubygem-zentest
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zentest
PORTVERSION=	3.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ZenTest-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby Unit Testing Utility

BUILD_DEPENDS=	rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=    ${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
