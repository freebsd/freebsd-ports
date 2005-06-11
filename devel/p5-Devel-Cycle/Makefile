# New ports collection makefile for:	Devel-Cycle
# Date created:	   16 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Cycle
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Find memory cycles in objects

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::Cycle.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	Perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
