# New ports collection makefile for:	p5-Gearman
# Date created:		Mon Mar 26 11:45:06 EDT 2007
# Whom:			Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	Gearman
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman client libraray for Perl

MODULE_DEPENDS=	p5-String-CRC32>=0.0:${PORTSDIR}/devel/p5-String-CRC32
RUN_DEPENDS+=	${MODULE_DEPENDS}
BUILD_DEPENDS+=	${MODULE_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Gearman::Client.3 Gearman::Task.3 Gearman::Worker.3
PLIST_FILES=	%%SITE_PERL%%/Gearman/Client.pm \
		%%SITE_PERL%%/Gearman/JobStatus.pm \
		%%SITE_PERL%%/Gearman/Objects.pm \
		%%SITE_PERL%%/Gearman/ResponseParser.pm \
		%%SITE_PERL%%/Gearman/ResponseParser/Taskset.pm \
		%%SITE_PERL%%/Gearman/Task.pm \
		%%SITE_PERL%%/Gearman/Taskset.pm \
		%%SITE_PERL%%/Gearman/Util.pm \
		%%SITE_PERL%%/Gearman/Worker.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Gearman/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Gearman \
		%%SITE_PERL%%/Gearman/ResponseParser \
		%%SITE_PERL%%/Gearman

.include <bsd.port.mk>
