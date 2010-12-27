# New ports collection makefile for:	Module::Info
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Info
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Provides information about Perl modules

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		module_info.1 pfunc.1
MAN3=		B::BUtils.3 B::Module::Info.3 Module::Info.3

.include <bsd.port.mk>
