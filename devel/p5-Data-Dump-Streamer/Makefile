# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

RUN_DEPENDS=	p5-B-Utils>=0.05:${PORTSDIR}/devel/p5-B-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DDS

MAN3=		DDS.3 Data::Dump::Streamer.3

.include <bsd.port.mk>
