# New ports collection makefile for:	p5-MP3-Tag
# Date created:		7 Feb 2005
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	MP3-Tag
PORTVERSION=	0.9707
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=MP3
PKGNAMEPREFIX=	p5-

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Module for reading tags of MP3 audio files

PERL_CONFIGURE=	yes

MAN1=		typeset_audio_dir.1 mp3info2.1
MAN3=		MP3::Tag.3 MP3::Tag::ID3v1.3 MP3::Tag::File.3 \
		MP3::Tag::CDDB_File.3 MP3::Tag::ParseData.3 MP3::Tag::Inf.3 \
		MP3::Tag::ID3v2.3 MP3::Tag::ID3v2-Data.3 MP3::Tag::LastResort.3

CONFLICTS=	p5-tagged-0.*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or newer
.endif

.include <bsd.port.post.mk>
