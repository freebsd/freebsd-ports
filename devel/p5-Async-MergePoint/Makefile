# Created by: Felippe M. Motta <lippe@shire.freebsd.org>
# $FreeBSD$

PORTNAME=	Async-MergePoint
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	johan@stromnet.se
COMMENT=	Perl modules that resynchronise diverged control flow

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

MAN3=		Async::MergePoint.3

PLIST_FILES=	%%SITE_PERL%%/Async/MergePoint.pm \
		%%SITE_PERL%%/mach/auto/Async/MergePoint/.packlist

PLIST_DIRS=	%%SITE_PERL%%/mach/auto/Async/MergePoint \
		%%SITE_PERL%%/mach/auto/Async \
		%%SITE_PERL%%/Async

.include <bsd.port.mk>
