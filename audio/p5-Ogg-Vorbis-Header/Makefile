# New ports collection makefile for:	p5-Ogg-Vorbis-Header
# Date created:		Sept 11 2004
# Whom:			Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	Ogg-Vorbis-Header
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate / fetch info from Ogg-Vorbis audio files

LIB_DEPENDS=	ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${SITE_PERL}/Inline/MakeMaker.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes

MAN3=		Ogg::Vorbis::Header.3

.include <bsd.port.mk>
