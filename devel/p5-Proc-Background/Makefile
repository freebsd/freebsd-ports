# New ports collection makefile for:	Proc-Background
# Date created:				Wed Jan  3 10:32:39 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Proc-Background
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Proc
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		timed-process.1
MAN3=		Proc::Background.3 \
		Proc::Background::Win32.3 \
		Proc::Background::Unix.3

.include <bsd.port.mk>
