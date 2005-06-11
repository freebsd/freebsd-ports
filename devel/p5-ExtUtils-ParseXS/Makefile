# New ports collection makefile for:	ExtUtils::ParseXS
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-ParseXS
PORTVERSION=	2.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Converts Perl XS code into C code

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/CBuilder.pm:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::ParseXS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
IGNORE=		Needs perl 5.6 or higher because of "/??{}/" in regexes
.endif

.include <bsd.port.post.mk>
