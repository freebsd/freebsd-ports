# New ports collection makefile for:	p5-IO-AIO
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-AIO
PORTVERSION=	3.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Asynchronous Input/Output

PERL_CONFIGURE=	yes

MAN3=		IO::AIO.3

post-patch:
	${PERL} -e 's,-lpthreads?,${PTHREAD_LIBS},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
