# New ports collection makefile for:	p5-Class-MethodMaker
# Date created:				2000-07-09
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=		Class-MethodMaker
PORTVERSION=		2.07
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=		p5-

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Perl module for creating generic methods

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec/Functions.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN3=	Class::MethodMaker.3 \
	Class::MethodMaker::Constants.3 \
	Class::MethodMaker::Engine.3 \
	Class::MethodMaker::OptExt.3 \
	Class::MethodMaker::V1Compat.3 \
	Class::MethodMaker::array.3 \
	Class::MethodMaker::hash.3 \
	Class::MethodMaker::scalar.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
