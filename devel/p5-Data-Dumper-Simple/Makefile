# New ports collection makefile for:	p5-Data-Dumper-Simple
# Date created:	   			Sep 9 2004
# Whom:		   			clsung
#
# $FreeBSD$
#

PORTNAME=	Data-Dumper-Simple
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Easily dump variables with names

PERL_CONFIGURE=	yes

MAN3=		Data::Dumper::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	${SITE_PERL}/Filter/Simple.pm:${PORTSDIR}/textproc/p5-Filter-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif
.if ${PERL_LEVEL} < 500601
IGNORE="Need at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>
