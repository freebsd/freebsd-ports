# Created by: Ruben van Staveren
# $FreeBSD$

PORTNAME=	Thread-Suspend
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Thread
PKGNAMEPREFIX=	p5-

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Suspend and resume operations for threads

USES=		perl5
USE_PERL5=	configure

MAN3=	Thread::Suspend.3

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} "----------------------------------------------------------"
	@${ECHO_MSG} "This module requires a threaded perl.  If your install"
	@${ECHO_MSG} "is not threaded please install lang/${PERL_PORT} with threads"
	@${ECHO_MSG} "----------------------------------------------------------"

.include <bsd.port.post.mk>
