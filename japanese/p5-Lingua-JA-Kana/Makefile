# New ports collection makefile for:	p5-Lingua-JA-Kana
# Date created:		14 May 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-JA-Kana
PORTVERSION=	0.04
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts between kanas and romaji

BUILD_DEPENDS=	p5-Test-Simple>=0.80:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
