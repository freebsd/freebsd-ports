# New ports collection makefile for:	Spiffy
# Date created:		15 Jul 2004
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Spiffy
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spiffy Perl Interface Framework For You

PERL_CONFIGURE=	yes

MAN3=		Spiffy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif
.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl then try again
.endif

.include <bsd.port.post.mk>
