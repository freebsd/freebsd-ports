# New ports collection makefile for:	p5-Data-Dump-Streamer
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in perl code form to a var or file

RUN_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/B/BUtils.pm:${PORTSDIR}/devel/p5-Module-Info
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DDS

MAN3=		DDS.3 Data::Dump::Streamer.3

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's,B::Utils,B::BUtils,g'

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6 or above
.endif

.include <bsd.port.post.mk>
