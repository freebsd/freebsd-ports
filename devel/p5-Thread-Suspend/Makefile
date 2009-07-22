# New ports collection makefile for: p5-Thread-Suspend
# Date created: 2007-03-18
# Whom: Ruben van Staveren
#
# $FreeBSD$
#

PORTNAME=	Thread-Suspend
PORTVERSION=	1.19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Thread
PKGNAMEPREFIX=	p5-

MAINTAINER=	ruben@verweg.com
COMMENT=	Suspend and resume operations for threads

RUN_DEPENDS=	p5-threads>=1.39:${PORTSDIR}/devel/p5-threads \
		p5-threads-shared>=1.01:${PORTSDIR}/devel/p5-threads-shared
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Thread::Suspend.3

pre-everything::
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "This module requires a threaded perl.  If your install"
	@${ECHO_MSG} "is not threaded please install lang/perl5.8 with threads"
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
