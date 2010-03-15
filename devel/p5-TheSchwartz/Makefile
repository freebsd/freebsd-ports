# New ports collection makefile for:	p5-TheSchwartz
# Date created:		2008-01-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	TheSchwartz
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/S/SI/SIXAPART
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reliable job queue

BUILD_DEPENDS=	p5-Data-ObjectDriver>=0:${PORTSDIR}/devel/p5-Data-ObjectDriver
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	schwartzmon.1
MAN3=	TheSchwartz.3 TheSchwartz::Job.3 TheSchwartz::Worker.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extras/check_schwartz ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/extras/thetop ${PREFIX}/bin/

.include <bsd.port.mk>
