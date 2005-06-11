# New ports collection makefile for:	Devel-SmallProf
# Date created:	   11 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-SmallProf
PORTVERSION=	2.00.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SA/SALVA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([0-9]+)$/_\1/}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Per-line Perl profiler

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::SmallProf.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again.
.endif

.include <bsd.port.post.mk>
