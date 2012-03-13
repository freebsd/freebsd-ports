# New ports collection makefile for:    p5-Convert-ASCII-Armour
# Date created:				2001/08/26
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	Convert-ASCII-Armour
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert binary octets into ASCII armoured messages

PERL_CONFIGURE=	yes

MAN3=		Convert::ASCII::Armour.3 Convert::ASCII::Armor.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
