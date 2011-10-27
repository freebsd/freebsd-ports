# New ports collection makefile for:	Ruby ActionSCript UTility
# Date created:		2 Dec 2007
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascut
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Ruby ActionSCript UTility

RUN_DEPENDS=	mongrel_rails:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-json_pure>=1.5.1:${PORTSDIR}/devel/rubygem-json_pure \
		rackup:${PORTSDIR}/www/rubygem-rack \
		fcsh:${PORTSDIR}/devel/flex-sdk

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rascut

.include <bsd.port.mk>
