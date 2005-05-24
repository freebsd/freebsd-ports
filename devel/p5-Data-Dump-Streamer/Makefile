# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in perl code form to a var or file

BUILD_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/B/Utils.pm:${PORTSDIR}/devel/p5-Module-Info
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::Dump::Streamer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
.endif
.if ${PERL_LEVEL} < 500600
IGNORE="Need at least perl 5.6 to build"
.endif

.include <bsd.port.post.mk>
