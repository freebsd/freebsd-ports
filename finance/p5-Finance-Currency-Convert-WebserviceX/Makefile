# New ports collection makefile for:	p5-Finance-Currency-Convert-WebserviceX
# Date Created:				27 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Finance-Currency-Convert-WebserviceX
PORTVERSION=	0.06001
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Lightweight currency conversion using WebserviceX.NET

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		p5-Module-Install>=0.65:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::Currency::Convert::WebserviceX.3

.include <bsd.port.mk>
