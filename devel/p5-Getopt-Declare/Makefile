# New ports collection makefile for:	devel/p5-Getopt-Declare
# Date created:				16 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Declare
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Getopt
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Getopt::Declare.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
