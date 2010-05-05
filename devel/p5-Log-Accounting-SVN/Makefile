# New ports collection makefile for:	p5-Log-Accounting-SVN
# Date created:		2006-06-26
# Whom:			Yuan-Chung Hsiao & <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Accounting-SVN
PORTVERSION=	0.01
PORTREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVN repository

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		p5-SVN-Log>=0:${PORTSDIR}/devel/p5-SVN-Log \
		p5-Algorithm-Accounting>=0:${PORTSDIR}/devel/p5-Algorithm-Accounting \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Log::Accounting::SVN.3

.include <bsd.port.mk>
