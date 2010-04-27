# New ports collection makefile for:	rubygem-echoe
# Date created:		2009-06-15
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	echoe
PORTVERSION=	3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	fauna

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rake tasks for docs, extension compiling, testing and deployment

RUN_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		rubyforge:${PORTSDIR}/devel/rubygem-rubyforge \
		rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
