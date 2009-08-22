# ex:ts=8
# New ports collection makefile for:	p5-tagged
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagged
PORTVERSION=	0.40
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN/MP3 \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read, change and write different tags of MP3 audio files

BUILD_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MP3::Tag::ID3v2.3 MP3::Tag.3 MP3::Tag::File.3 \
	MP3::Tag::ID3v2-Data.3 MP3::Tag::ID3v1.3

CONFLICTS=	p5-MP3-Tag-0.*

.include <bsd.port.mk>
