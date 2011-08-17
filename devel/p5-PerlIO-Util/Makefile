# New ports collection makefile for:	p5-PerlIO-Util
# Date created:		2011-08-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-Util
PORTVERSION=	0.72
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A selection of general PerlIO utilities

PERL_CONFIGURE=	5.8.8+

MAN3=		PerlIO::Util.3 \
		PerlIO::Util::JA.3 \
		PerlIO::creat.3 \
		PerlIO::dir.3 \
		PerlIO::excl.3 \
		PerlIO::flock.3 \
		PerlIO::reverse.3 \
		PerlIO::tee.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
