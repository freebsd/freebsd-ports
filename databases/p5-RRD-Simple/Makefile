# New ports collection makefile for:	RRD-Simple
# Date created:				2006/07/21
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	RRD-Simple
PORTVERSION=	1.43
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Proc/NICOLAW
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Simple interface to create and store data in RRD files

BUILD_DEPENDS=	${SITE_PERL}/Test/Deep.pm:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Pod>=0.90:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
MAN3=		RRD::Simple.3 RRD::Simple::Examples.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
