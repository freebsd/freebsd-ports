# New ports collection makefile for:	p5-File-Append-TempFile
# Date created:				February 10th, 2006
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Append-TempFile
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Append data to files using a temporary copy

.if !defined(WITHOUT_TEST_POD_COVERAGE)
BUILD_DEPENDS=	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

PERL_CONFIGURE=	yes

MAN3=		File::Append::TempFile.3

test:		build
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		needs Perl 5.6 or later
.endif

.include <bsd.port.post.mk>
