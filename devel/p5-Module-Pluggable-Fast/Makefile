# ex:ts=8
# Ports collection makefile for:	p5-Module-Pluggable-Fast
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Module-Pluggable-Fast
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast plugins with instantiation

BUILD_DEPENDS=	${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Pluggable::Fast.3

.include <bsd.port.mk>
