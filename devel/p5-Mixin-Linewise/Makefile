# New ports collection makefile for:	p5-Mixin-Linewise
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Mixin-Linewise
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RJ/RJBS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Write your linewise code for handles; this does the rest

BUILD_DEPENDS+=	p5-Sub-Exporter>=0.900:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS+=	p5-Sub-Exporter>=0.900:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		Mixin::Linewise::Readers.3 \
		Mixin::Linewise::Writers.3 \
		Mixin::Linewise.3
PLIST_FILES+=	%%SITE_PERL%%/Mixin/Linewise/Readers.pm \
		%%SITE_PERL%%/Mixin/Linewise/Writers.pm \
		%%SITE_PERL%%/Mixin/Linewise.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Mixin/Linewise/.packlist
PLIST_DIRS+=	%%SITE_PERL%%/Mixin/Linewise \
		%%SITE_PERL%%/Mixin \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Mixin/Linewise \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Mixin

.include <bsd.port.mk>
