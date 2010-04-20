# New ports collection makefile for:  Module-Install-Template
# Date created:		07 December 2009
# Whom:			gugu
#
# $FreeBSD$
#

PORTNAME=	Module-Install-Template
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Treat module source code as a template

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+
MAN3=	Module::Install::Template.3

.include <bsd.port.mk>
