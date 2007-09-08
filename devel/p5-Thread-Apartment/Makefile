# New ports collection makefile for:	p5-Thread-Apartment
# Date created:		2006-08-29
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Thread-Apartment
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Thread
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Apartment threading wrapper for Perl objects

RUN_DEPENDS=	p5-Thread-Queue-Duplex>=0.92:${PORTSDIR}/devel/p5-Thread-Queue-Duplex \
		p5-Class-ISA>=0.32:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Class-Inspector>=1.08:${PORTSDIR}/devel/p5-Class-Inspector
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Thread::Apartment.3

.include <bsd.port.mk>
