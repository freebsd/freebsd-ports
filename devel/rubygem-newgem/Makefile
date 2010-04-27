# Ports collection makefile for:	newgem
# Date created:				January 12, 2010
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	newgem
PORTVERSION=	1.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Bundle ruby libraries into gems

BUILD_DEPENDS=	rubygem-activesupport>=2.0.2:${PORTSDIR}/devel/rubygem-activesupport \
  rubygem-rubigen>=1.5.1:${PORTSDIR}/devel/rubygem-rubigen \
  rubygem-hoe>=1.8.0:${PORTSDIR}/devel/rubygem-hoe \
  rubygem-redcloth>=4.0.0:${PORTSDIR}/www/rubygem-redcloth \
  rubygem-syntax>=1.0.0:${PORTSDIR}/textproc/rubygem-syntax
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	bin/newgem

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
