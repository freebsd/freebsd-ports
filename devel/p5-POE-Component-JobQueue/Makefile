# New ports collection makefile for:	POE-Component-JobQueue
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-JobQueue
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://poe.perl.org/poedown/
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::JobQueue.3

.include <bsd.port.mk>
