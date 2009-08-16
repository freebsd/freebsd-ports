# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

BUILD_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/${PERL_ARCH}/B/Utils.pm:${PORTSDIR}/devel/p5-B-Utils \
		${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DDS

MAN3=		DDS.3 Data::Dump::Streamer.3

.include <bsd.port.mk>
