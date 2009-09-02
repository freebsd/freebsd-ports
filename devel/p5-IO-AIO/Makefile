# New ports collection makefile for:	p5-IO-AIO
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-AIO
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Asynchronous Input/Output

BUILD_DEPENDS=	p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::AIO.3

post-patch:
	${PERL} -e 's,-lpthreads?,${PTHREAD_LIBS},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
