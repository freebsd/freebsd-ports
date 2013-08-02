# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tagged
PORTVERSION=	0.40
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN/MP3 \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read, change, and write different tags of MP3 audio files

USES=		perl5
USE_PERL5=	configure

MAN3=	MP3::Tag::ID3v2.3 MP3::Tag.3 MP3::Tag::File.3 \
	MP3::Tag::ID3v2-Data.3 MP3::Tag::ID3v1.3

CONFLICTS=	p5-MP3-Tag-0.*

.include <bsd.port.mk>
