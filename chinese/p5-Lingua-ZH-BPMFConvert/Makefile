# New ports collection makefile for:	p5-Lingua-ZH-BPMFConvert
# Date created:		2006-09-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-ZH-BPMFConvert
PORTVERSION=	0.01
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Rule-based conversion of BPMF (bopomofo) into Hanyu Pinyin

PERL_CONFIGURE=	yes

MAN3=		Lingua::ZH::BPMFConvert.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
