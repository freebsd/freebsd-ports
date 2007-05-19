# New ports collection makefile for:	p5-Log-Accounting-SVN
# Date created:		2006-06-26
# Whom:			Yuan-Chung Hsiao & <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Accounting-SVN
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVN repository

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl \
		p5-SVN-Log>=0:${PORTSDIR}/devel/p5-SVN-Log \
		p5-Algorithm-Accounting>=0:${PORTSDIR}/devel/p5-Algorithm-Accounting \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Log::Accounting::SVN.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	currently requires at least Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
