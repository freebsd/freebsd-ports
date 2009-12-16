# New ports collection makefile for:	p5-uni-perl
# Date created:		2009-10-20
# Whom:			Mons Anderson <mons@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	uni-perl
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MO/MONS
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Modern perl with unicode

RUN_DEPENDS=	p5-Data-Dumper>=2:${PORTSDIR}/devel/p5-Data-Dumper \
	p5-Encode>=2.37:${PORTSDIR}/converters/p5-Encode \
	p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.10.0+

MAN3=	uni::perl.3

.include <bsd.port.mk>
