# New ports collection makefile for:	devel/p5-Git-PurePerl
# Date created:				Nov 21 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Git-PurePerl
PORTVERSION=	0.41
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/L/LB/LBROCARD
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Pure Perl interface to Git repositories

RUN_DEPENDS=	p5-Archive-Extract>=0:${PORTSDIR}/archivers/p5-Archive-Extract \
		p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-Data-Stream-Bulk>=0:${PORTSDIR}/devel/p5-Data-Stream-Bulk \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Git::PurePerl.3

.include <bsd.port.mk>
