# New ports collection makefile for:	p5-Hash-FieldHash
# Date created:		2011-08-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Hash-FieldHash
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A lightweight field hash implementation

TEST_DEPENDS=	p5-Test-LeakTrace>=0.07:${PORTSDIR}/devel/p5-Test-LeakTrace

PERL_CONFIGURE=	yes

MAN3=		Hash::FieldHash.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS+=	p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort \
		p5-parent>=0.221:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0.221:${PORTSDIR}/devel/p5-parent
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
