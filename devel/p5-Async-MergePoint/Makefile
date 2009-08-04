# New ports collection makefile for:	p5-Async-MergePoint2
# Date created:		2009-08-04
# Whom:			Felippe M. Motta <lippe@shire.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Async-MergePoint
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	johan@stromnet.se
COMMENT=	Perl modules that resynchronise diverged control flow

PERL_CONFIGURE=	yes

MAN3=		Async::MergePoint.3

PLIST_FILES=	%%SITE_PERL%%/Async/MergePoint.pm \
		%%SITE_PERL%%/mach/auto/Async/MergePoint/.packlist

PLIST_DIRS=	%%SITE_PERL%%/mach/auto/Async/MergePoint \
		%%SITE_PERL%%/mach/auto/Async \
		%%SITE_PERL%%/Async

.include <bsd.port.mk>
