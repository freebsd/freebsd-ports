# New ports collection makefile for:	POE-Component-Child
# Date created:	   31 January 2004
# Whom:		   Zach Thompson <lin-chi@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Child
PORTVERSION=	1.33
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	lin-chi@lastamericanempire.com
COMMENT=	POE child management

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Child.3

post-install:

.include <bsd.port.mk>
