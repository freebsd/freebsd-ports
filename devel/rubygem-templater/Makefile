# Ports collection makefile for:	rubygem-templater
# Date created:				03 February 2009
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	templater
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby code generation framework

BUILD_DEPENDS=	rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-extlib>=0.9.5:${PORTSDIR}/devel/rubygem-extlib \
		rubygem-diff-lcs>=1.1.2:${PORTSDIR}/textproc/rubygem-diff-lcs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
