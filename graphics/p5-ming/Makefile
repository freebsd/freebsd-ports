# New ports collection makefile for:	p5-ming
# Date created:		18 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTREVISION=	1
CATEGORIES=	graphics perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 module for Ming which allows you to create Flash 4/5 movies

CONFIGURE_ARGS=	--enable-perl
INSTALL_WRKSRC=	${WRKSRC}/perl_ext
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
PATCH_WRKSRC=	${WRKSRC}/perl_ext
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
USES=		perl5

MASTERDIR=	${.CURDIR}/../../graphics/ming
SLAVEPORT=	p5

MAN3=		SWF.3 \
		SWF::Action.3 \
		SWF::BinaryData.3 \
		SWF::Bitmap.3 \
		SWF::Blur.3 \
		SWF::BrowserFont.3 \
		SWF::Button.3 \
		SWF::ButtonRecord.3 \
		SWF::CXform.3 \
		SWF::Character.3 \
		SWF::Constants.3 \
		SWF::DisplayItem.3 \
		SWF::Fill.3 \
		SWF::Filter.3 \
		SWF::FilterMatrix.3 \
		SWF::Font.3 \
		SWF::FontCharacter.3 \
		SWF::FontCollection.3 \
		SWF::Gradient.3 \
		SWF::InitAction.3 \
		SWF::Matrix.3 \
		SWF::Morph.3 \
		SWF::Movie.3 \
		SWF::MovieClip.3 \
		SWF::PrebuiltClip.3 \
		SWF::Shadow.3 \
		SWF::Shape.3 \
		SWF::Sound.3 \
		SWF::SoundInstance.3 \
		SWF::SoundStream.3 \
		SWF::Sprite.3 \
		SWF::Text.3 \
		SWF::TextField.3 \
		SWF::VideoStream.3

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	cd ${INSTALL_WRKSRC}/examples/ && ${INSTALL_DATA} *.cgi ${EXAMPLESDIR}/
.endif

.include "${MASTERDIR}/Makefile"
