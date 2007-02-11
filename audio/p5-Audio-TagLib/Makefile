# New ports collection makefile for:	Audio-TagLib
# Date created:	   04 July 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Audio-TagLib
PORTVERSION=	1.43
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Audio
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Library for reading and editing audio meta data

BUILD_DEPENDS=	taglib-config:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ICONV=	YES
PERL_CONFIGURE=	YES
CONFIGURE_ARGS+=	CC="${CXX}" LD="${CXX}" LIBS="-L/usr/local/lib -ltag -liconv"

MAN3=		Audio::TagLib.3 Audio::TagLib::APE::Footer.3 \
		Audio::TagLib::APE::Item.3 Audio::TagLib::APE::ItemListMap.3 \
		Audio::TagLib::APE::ItemListMap::Iterator.3 \
		Audio::TagLib::APE::Tag.3 Audio::TagLib::AudioProperties.3 \
		Audio::TagLib::ByteVector.3 \
		Audio::TagLib::ByteVector::Iterator.3 \
		Audio::TagLib::ByteVectorList.3 Audio::TagLib::FLAC::File.3 \
		Audio::TagLib::FLAC::Properties.3 Audio::TagLib::File.3 \
		Audio::TagLib::FileRef.3 \
		Audio::TagLib::FileRef::FileTypeResolver.3 \
		Audio::TagLib::ID3v1.3 Audio::TagLib::ID3v1::GenreMap.3 \
		Audio::TagLib::ID3v1::GenreMap::Iterator.3 \
		Audio::TagLib::ID3v1::StringHandler.3 \
		Audio::TagLib::ID3v1::Tag.3 \
		Audio::TagLib::ID3v2::AttachedPictureFrame.3 \
		Audio::TagLib::ID3v2::CommentsFrame.3 \
		Audio::TagLib::ID3v2::ExtendedHeader.3 \
		Audio::TagLib::ID3v2::Footer.3 Audio::TagLib::ID3v2::Frame.3 \
		Audio::TagLib::ID3v2::FrameFactory.3 \
		Audio::TagLib::ID3v2::FrameList.3 \
		Audio::TagLib::ID3v2::FrameList::Iterator.3 \
		Audio::TagLib::ID3v2::FrameListMap.3 \
		Audio::TagLib::ID3v2::FrameListMap::Iterator.3 \
		Audio::TagLib::ID3v2::Header.3 \
		Audio::TagLib::ID3v2::RelativeVolumeFrame.3 \
		Audio::TagLib::ID3v2::RelativeVolumeFrame::PeakVolume.3 \
		Audio::TagLib::ID3v2::SynchData.3 Audio::TagLib::ID3v2::Tag.3 \
		Audio::TagLib::ID3v2::TextIdentificationFrame.3 \
		Audio::TagLib::ID3v2::UniqueFileIdentifierFrame.3 \
		Audio::TagLib::ID3v2::UnknownFrame.3 \
		Audio::TagLib::ID3v2::UserTextIdentificationFrame.3 \
		Audio::TagLib::MPC::File.3 Audio::TagLib::MPC::Properties.3 \
		Audio::TagLib::MPEG::File.3 Audio::TagLib::MPEG::Header.3 \
		Audio::TagLib::MPEG::Properties.3 \
		Audio::TagLib::MPEG::XingHeader.3 \
		Audio::TagLib::Ogg::FLAC::File.3 \
		Audio::TagLib::Ogg::FieldListMap.3 \
		Audio::TagLib::Ogg::FieldListMap::Iterator.3 \
		Audio::TagLib::Ogg::File.3 Audio::TagLib::Ogg::Page.3 \
		Audio::TagLib::Ogg::PageHeader.3 \
		Audio::TagLib::Ogg::Vorbis::File.3 \
		Audio::TagLib::Ogg::Vorbis::Properties.3 \
		Audio::TagLib::Ogg::XiphComment.3 Audio::TagLib::String.3 \
		Audio::TagLib::String::Iterator.3 Audio::TagLib::StringList.3 \
		Audio::TagLib::Tag.3 Audio::TagLib::Vorbis::File.3 \
		Audio::TagLib::Vorbis::Properties.3

post-configure:
	${REINPLACE_CMD} -e "s,^CC = .*\$$,CC = ${CXX}," ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
IGNORE=	perl 5.8.3 or newer required. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
