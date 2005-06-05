# New ports collection makefile for:	p5-Image-ExifTool
# Date Created:				15 Sep 2004
# Whom:					Tod McQuillin <devin@spamcop.net>
#
# $FreeBSD$
#

PORTNAME=	Image-ExifTool
PORTVERSION=	5.25
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@spamcop.net
COMMENT=	Perl module for getting EXIF data from image files

PERL_CONFIGURE=	yes

MAN3=		File::RandomAccess.3 \
		Image::ExifTool.3 \
		Image::ExifTool::BuildTagLookup.3 \
		Image::ExifTool::Canon.3 \
		Image::ExifTool::CanonCustom.3 \
		Image::ExifTool::CanonRaw.3 \
		Image::ExifTool::Casio.3 \
		Image::ExifTool::Exif.3 \
		Image::ExifTool::Fixup.3 \
		Image::ExifTool::FujiFilm.3 \
		Image::ExifTool::GPS.3 \
		Image::ExifTool::GeoTiff.3 \
		Image::ExifTool::ICC_Profile.3 \
		Image::ExifTool::IPTC.3 \
		Image::ExifTool::Jpeg2000.3 \
		Image::ExifTool::Kodak.3 \
		Image::ExifTool::MakerNotes.3 \
		Image::ExifTool::Minolta.3 \
		Image::ExifTool::Nikon.3 \
		Image::ExifTool::Olympus.3 \
		Image::ExifTool::Panasonic.3 \
		Image::ExifTool::Pentax.3 \
		Image::ExifTool::Photoshop.3 \
		Image::ExifTool::PrintIM.3 \
		Image::ExifTool::Ricoh.3 \
		Image::ExifTool::Sanyo.3 \
		Image::ExifTool::Shortcuts.3 \
		Image::ExifTool::Sigma.3 \
		Image::ExifTool::Sony.3 \
		Image::ExifTool::TagLookup.3 \
		Image::ExifTool::TagNames.3 \
		Image::ExifTool::Unknown.3 \
		Image::ExifTool::WriteCanonRaw.3 \
		Image::ExifTool::WriteExif.3 \
		Image::ExifTool::WriteIPTC.3 \
		Image::ExifTool::WritePhotoshop.3 \
		Image::ExifTool::WriteXMP.3 \
		Image::ExifTool::Writer.3 \
		Image::ExifTool::XMP.3

MAN1=		exiftool.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/TagNames
	${INSTALL_DATA} ${WRKSRC}/html/TagNames/*.html ${DOCSDIR}/TagNames
.endif

.include <bsd.port.mk>
