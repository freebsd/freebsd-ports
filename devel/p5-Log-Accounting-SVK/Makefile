# New ports collection makefile for:	devel/p5-Log-Accounting-SVK
# Date created:				21 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Log-Accounting-SVK
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVK repository

BUILD_DEPENDS=	${SITE_PERL}/SVK.pm:${PORTSDIR}/devel/svk \
		${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy \
		${SITE_PERL}/Algorithm/Accounting.pm:${PORTSDIR}/devel/p5-Algorithm-Accounting
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Log::Accounting::SVK.3
.include <bsd.port.mk>
