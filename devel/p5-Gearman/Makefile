# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Gearman
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman client libraray for Perl

RUN_DEPENDS+=	p5-String-CRC32>=0.0:${PORTSDIR}/devel/p5-String-CRC32

USES=		perl5
USE_PERL5=	configure

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
