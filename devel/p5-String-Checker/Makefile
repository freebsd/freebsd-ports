# New ports collection makefile for:	String-Checker
# Date created:				Mon Jan  1 11:03:15 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	String-Checker
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module implementing an extensible string validation interface

BUILD_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		String::Checker.3

.include <bsd.port.mk>
