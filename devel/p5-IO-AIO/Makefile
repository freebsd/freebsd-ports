# New ports collection makefile for:	p5-IO-AIO
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-AIO
PORTVERSION=	2.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Asynchronous Input/Output

PERL_CONFIGURE=	yes

MAN3=		IO::AIO.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

post-patch:
	${PERL} -e 's,-lpthreads?,${PTHREAD_LIBS},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
