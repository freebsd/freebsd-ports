# ex:ts=8
# Ports collection makefile for:	p5-Module-Pluggable-Fast
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Module-Pluggable-Fast
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Fast plugins with instantiation

BUILD_DEPENDS=	p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Pluggable::Fast.3

.include <bsd.port.mk>
