# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.22
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

RUN_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-B-Utils>=0:${PORTSDIR}/devel/p5-B-Utils \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-PadWalker>=0.99:${PORTSDIR}/devel/p5-PadWalker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Data::Dump::Streamer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
