# New ports collection makefile for:	JSON-XS
# Date created:		25 Mar 2007
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-XS
PORTVERSION=	1.10
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/ML/MLEHMANN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

PERL_CONFIGURE=	yes
MAN3=		JSON::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
