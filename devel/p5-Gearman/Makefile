# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Gearman
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman client libraray for Perl

RUN_DEPENDS+=	p5-String-CRC32>=0.0:devel/p5-String-CRC32

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Gearman/Client.pm \
		%%SITE_PERL%%/Gearman/JobStatus.pm \
		%%SITE_PERL%%/Gearman/Objects.pm \
		%%SITE_PERL%%/Gearman/ResponseParser.pm \
		%%SITE_PERL%%/Gearman/ResponseParser/Taskset.pm \
		%%SITE_PERL%%/Gearman/Task.pm \
		%%SITE_PERL%%/Gearman/Taskset.pm \
		%%SITE_PERL%%/Gearman/Util.pm \
		%%SITE_PERL%%/Gearman/Worker.pm \
		%%PERL5_MAN3%%/Gearman::Client.3.gz \
		%%PERL5_MAN3%%/Gearman::Task.3.gz \
		%%PERL5_MAN3%%/Gearman::Worker.3.gz

.include <bsd.port.mk>
