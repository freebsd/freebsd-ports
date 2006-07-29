# New ports collection makefile for:	Baseball-Sabermetrics
# Date created:				2006/07/21
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Baseball-Sabermetrics
PORTVERSION=	0.01
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Baseball/VICTOR
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_01

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A Baseball Statistics Module

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Baseball::Sabermetrics.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
