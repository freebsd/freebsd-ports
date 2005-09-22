# New ports collection makefile for:	devel/p5-Data-ACL
# Date created:				22 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ACL
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::ACL - Perl extension for simple ACL lists

BUILD_DEPENDS=	${SITE_PERL}/Set/NestedGroups.pm:${PORTSDIR}/devel/p5-Set-NestedGroups
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::ACL.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
