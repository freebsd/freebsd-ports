# New ports collection makefile for:	p5-Test-Pod-Coverage
# Date created:				20 november 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Pod-Coverage
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Check for pod coverage in your distribution

RUN_DEPENDS=	p5-Pod-Coverage>0:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Test::Pod::Coverage.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e '$$_ = "" if m|use warnings;|;' \
		     -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/Makefile.PL \
		${WRKSRC}/Coverage.pm
.endif
.include <bsd.port.post.mk>
