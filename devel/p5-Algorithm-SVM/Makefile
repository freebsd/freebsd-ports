# New ports collection makefile for:	Algorithm::SVM
# Date created:				Dec 27 2003
# Whom:					Cheng-Lung Sung	<clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-SVM
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl bindings for the libsvm Support Vector Machine library

PERL_CONFIGURE=	yes

MAN3=		Algorithm::SVM.3 \
		Algorithm::SVM::DataSet.3

CC=		c++

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
