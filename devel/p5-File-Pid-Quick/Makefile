# Ports collection makefile for:	devel-p5-File-Pid-Quick
# Date created:				03 April 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=		File-Pid-Quick
PORTVERSION=		1.02
CATEGORIES=		devel perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=		p5-

MAINTAINER=		freebsdports@chillibear.com
COMMENT=		Associates a PID file with your script

PERL_CONFIGURE=	yes

MAN3=	File::Pid::Quick.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
