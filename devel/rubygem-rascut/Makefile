# New ports collection makefile for:	Ruby ActionSCript UTility
# Date created:		2 Dec 2007
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascut
PORTVERSION=	0.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	hotchpotch

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Ruby ActionSCript UTility

BUILD_DEPENDS=	mongrel_rails:${PORTSDIR}/www/rubygem-mongrel \
		rackup:${PORTSDIR}/www/rubygem-rack \
		fcsh:${PORTSDIR}/devel/flex_compiler_shell

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
