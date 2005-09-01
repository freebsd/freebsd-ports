# New ports collection makefile for:	p5-Encode-HanExtra
# Date created:				19 August 2005
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Encode-HanExtra
PORTVERSION=	0.10
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Extra sets of Chinese encodings

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
IGNORE=		requires Perl 5.7.3 or above
.endif

.include <bsd.port.post.mk>
