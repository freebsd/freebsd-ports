# New ports collection makefile for:	p5-Audio-Musepack
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Audio-Musepack
PORTVERSION=	0.7
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Interface to Musepack file information and APE tag fields

BUILD_DEPENDS=	p5-MP3-Info>=1.20:${PORTSDIR}/audio/p5-MP3-Info
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Audio::APETags.3 \
		Audio::APE.3 \
		Audio::Musepack.3

.include <bsd.port.mk>
