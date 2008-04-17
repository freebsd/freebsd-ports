# New ports collection makefile for:	p5-Ogg-Vorbis-Header
# Date created:		Sept 11 2004
# Whom:			Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	Ogg-Vorbis-Header
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Manipulate / fetch info from Ogg-Vorbis audio files

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${SITE_PERL}/Inline/MakeMaker.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Ogg::Vorbis::Header.3

.include <bsd.port.mk>
