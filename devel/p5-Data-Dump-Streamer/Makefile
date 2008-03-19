# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.08.40
DISTVERSION=	${PORTVERSION:C/\.(..)$/-\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

RUN_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/B/Utils.pm:${PORTSDIR}/devel/p5-B-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DDS

MAN3=		DDS.3 Data::Dump::Streamer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker
.endif

.include <bsd.port.post.mk>
