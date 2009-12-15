# New ports collection makefile for:    p5-Convert-ASCII-Armour
# Date created:				2001/08/26
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	Convert-ASCII-Armour
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert binary octets into ASCII armoured messages

RUN_DEPENDS=	p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Convert::ASCII::Armour.3 Convert::ASCII::Armor.3

.include <bsd.port.mk>
