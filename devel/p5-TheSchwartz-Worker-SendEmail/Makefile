# New ports collection makefile for:	p5-TheSchwartz-Worker-SendEmail
# Date created:		2010-11-18
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	TheSchwartz-Worker-SendEmail
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	TheSchwartz Worker Task to Send Email

BUILD_DEPENDS=	p5-TheSchwartz>=0:${PORTSDIR}/devel/p5-TheSchwartz
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	TheSchwartz::Worker::SendEmail.3

.include <bsd.port.mk>
