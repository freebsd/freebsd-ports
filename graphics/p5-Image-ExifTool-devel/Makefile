# New ports collection makefile for:	p5-Image-ExifTool
# Date Created:				15 Sep 2004
# Whom:					Tod McQuillin <devin@spamcop.net>
#
# $FreeBSD$
#

PORTNAME=	Image-ExifTool
PORTVERSION=	6.00
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@spamcop.net
COMMENT=	Perl module for getting EXIF data from image files

PERL_CONFIGURE=	yes

MANTAGS=	AFCP AIFF APP12 ASF BMP BuildTagLookup Canon CanonCustom \
		CanonRaw Casio DICOM DNG Exif Fixup FujiFilm GIF GPS GeoTiff \
		HtmlDump ICC_Profile ID3 IPTC JVC Jpeg2000 Kodak KyoceraRaw \
		Leaf MIFF MNG MakerNotes Minolta Nikon NikonCapture Olympus \
		PDF PICT PNG PPM Panasonic Pentax Photoshop PostScript \
		PrintIM QuickTime RIFF Ricoh Sanyo Shift Shortcuts Sigma \
		SigmaRaw Sony TagLookup TagNames Unknown WriteCanonRaw \
		WriteExif WriteIPTC WritePNG WritePhotoshop WriteXMP Writer \
		XMP

MAN3=		File::RandomAccess.3 \
		Image::ExifTool.3 \
		${MANTAGS:S/^/Image::ExifTool::/:S/$/.3/}

MAN1=		exiftool.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/TagNames
	${INSTALL_DATA} ${WRKSRC}/html/TagNames/*.html ${DOCSDIR}/TagNames
.endif

# Maintainer section
mantags:
	@cd ${LOCALBASE}/lib/perl5/5.8.7/man/man3/ && \
	ls Image::ExifTool::* | cut -f5 -d: | cut -f1 -d. | ${TR} "\n" " "

.include <bsd.port.mk>
