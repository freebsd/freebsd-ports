# New ports collection makefile for:	devel/p5-Lingua-JA-Fold
# Date created:				07 November 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-JA-Fold
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lingua::JA::Fold - fold a Japanese text

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::JA::Fold.3

.include <bsd.port.mk>
