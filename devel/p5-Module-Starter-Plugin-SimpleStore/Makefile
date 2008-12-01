# New ports collection makefile for:	devel/p5-Module-Starter-Plugin-SimpleStore
# Date created:				15 November 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	Module-Starter-Plugin-SimpleStore
PORTVERSION=	0.143
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Provide methods of retrieving templates for Module::Starter

BUILD_DEPENDS=	p5-Module-Starter>=1.32:${PORTSDIR}/devel/p5-Module-Starter

PERL_CONFIGURE=	5.8.0+

MAN3=	Module::Starter::Plugin::InlineStore.3 \
	Module::Starter::Plugin::DirStore.3 \
	Module::Starter::Plugin::ModuleStore.3

.include <bsd.port.mk>
