# New ports collection makefile for:	OOTools
# Date created:				July 22 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	OOTools
PORTVERSION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DO/DOMIZIO
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl module collection to easily create constructors methods

PERL_CONFIGURE=	YES

MAN3=		Class::constr.3 \
		Class::groups.3 \
		Class::props.3	\
		Class::Util.3	\
		Class::Error.3	\
		Object::groups.3 \
		Object::props.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
