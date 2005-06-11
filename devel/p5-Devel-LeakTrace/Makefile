# New ports collection makefile for:	Devel-LeakTrace
# Date created:	   19 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-LeakTrace
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Indicate where leaked variables are coming from

PERL_MODBUILD=	yes
USE_GNOME=	glib12

MAN3=		Devel::LeakTrace.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE= Perl 5.6 or newer required. Install lang/perl5.8 and try again.
.endif

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
