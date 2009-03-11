# New ports collection makefile for:	p5-TheSchwartz
# Date created:		2008-01-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	TheSchwartz
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reliable job queue

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Data/ObjectDriver.pm:${PORTSDIR}/devel/p5-Data-ObjectDriver

PERL_CONFIGURE=	5.8.0+

MAN3=		TheSchwartz.3 TheSchwartz::Job.3 TheSchwartz::Worker.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extras/check_schwartz ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/extras/thetop ${PREFIX}/bin/

.include <bsd.port.mk>
