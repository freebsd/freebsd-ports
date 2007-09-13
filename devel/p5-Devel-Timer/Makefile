# New ports collection makefile for:   p5-Devel-Timer
# Date created:		2006-12-11
# Whom:			Cory R. King <coryking@mozimediacom>
#
# $FreeBSD$
#

PORTNAME=	Devel-Timer
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Track and report execution time for parts of code

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Devel::Timer.3

post-extract:
	@${PERL} -pi -e '$$_ = undef if /''OPTIMIZE''/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
