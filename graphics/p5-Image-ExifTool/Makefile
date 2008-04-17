# New ports collection makefile for:	p5-Image-ExifTool
# Date Created:				15 Sep 2004
# Whom:					Tod McQuillin <devin@spamcop.net>
#
# $FreeBSD$
#

PORTNAME=	Image-ExifTool
PORTVERSION=	7.00
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@spamcop.net
COMMENT=	Perl module for getting EXIF data from image files

PERL_CONFIGURE=	yes

MANTAGS=	AFCP AIFF APE APP12 ASF BMP BigTIFF BuildTagLookup	 \
		Canon CanonCustom CanonRaw CanonVRD Casio DICOM DNG Exif \
		FLAC Fixup Flash FlashPix FotoStation FujiFilm GIF GPS	 \
		GeoTiff HTML HP HtmlDump ICC_Profile ID3 IPTC JPEG JVC	 \
		Jpeg2000 Kodak KyoceraRaw Leaf MIE MIFF MNG MPC MPEG	 \
		MakerNotes Minolta MinoltaRaw Nikon NikonCapture Olympus \
		PDF PICT PNG PPM Panasonic Pentax PhotoMechanic		 \
		Photoshop PostScript PrintIM QuickTime RIFF Real Ricoh	 \
		Sanyo Shift Shortcuts Sigma SigmaRaw Sony TagLookup	 \
		TagNames Unknown Vorbis WriteCanonRaw WriteExif		 \
		WriteIPTC WritePNG WritePhotoshop WritePostScript	 \
		WriteXMP Writer XMP

MAN3=		File::RandomAccess.3	\
		Image::ExifTool.3 Image::ExifTool::MIEUnits.3 \
		${MANTAGS:S/^/Image::ExifTool::/:S/$/.3/}

MAN1=		exiftool.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.css ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/TagNames
	${INSTALL_DATA} ${WRKSRC}/html/TagNames/*.html ${DOCSDIR}/TagNames
.endif

# Maintainer section
mantags:
	@cd ${LOCALBASE}/lib/perl5/${PERL_VERSION}/man/man3/ && \
		ls Image::ExifTool::* | \
		cut -f5 -d: | \
		cut -f1 -d. | \
		${TR} "\n" " "

.include <bsd.port.mk>
