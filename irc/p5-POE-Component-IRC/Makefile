# ex:ts=8
# New ports collection makefile for:	POE::Component::IRC
# Date created:		Aug 19, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC
PORTVERSION=	2.1
CATEGORIES=	irc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::Filter-CTCP.3 \
		POE::Component::IRC.3 \
		POE::Component::Filter-IRC.3

.include <bsd.port.mk>
