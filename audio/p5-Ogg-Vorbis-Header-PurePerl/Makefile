# New ports collection makefile for:	p5-Ogg-Vorbis-Header-PurePerl
# Date created:		2007-09-10
# Whom:			Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Ogg-Vorbis-Header-PurePerl
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=Ogg
PKGNAMEPREFIX=	p5-

MAINTAINER=	dominique.goncalves@gmail.com
COMMENT=	Manipulate / fetch info from Ogg-Vorbis audio files

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis

PERL_CONFIGURE=	yes

MAN3=		Ogg::Vorbis::Header::PurePerl.3

.include <bsd.port.mk>
