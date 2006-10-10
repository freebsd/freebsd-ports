# New ports collection makefile for:	p5-Lingua-Han-PinYin
# Date created:		2006-09-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-Han-PinYin
PORTVERSION=	0.06
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Retrieve the Mandarin(PinYin) of Chinese character(HanZi)

RUN_DEPENDS=	${SITE_PERL}/Lingua/Han/Utils.pm:${PORTSDIR}/chinese/p5-Lingua-Han-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Lingua::Han::PinYin.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from converters/p5-Lingua-Han-Utils
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
