# New ports collection makefile for:	p5-Image-ExifTool
# Date Created:				15 Sep 2004
# Whom:					Tod McQuillin <devin@spamcop.net>
#
# $FreeBSD$
#

# Note: This port tracks the "production release" of ExifTool as given
# by http://www.sno.phy.queensu.ca/~phil/exiftool/history.html
#
# Please make sure you are updating to the latest production release
# before updating the version of this port.

PORTNAME=	Image-ExifTool
PORTVERSION=	8.25
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@spamcop.net
COMMENT=	Perl module for getting EXIF data from image files

PERL_CONFIGURE=	yes

MANTAGS=	AFCP AIFF APE APP12 ASF BMP BigTIFF BuildTagLookup BZZ	 \
		Canon CanonCustom CanonRaw CanonVRD Casio Charset	 \
		CaptureOne DICOM DNG DjVu EXE Exif FLAC Fixup Flash	 \
		FlashPix Font FotoStation FujiFilm GIF GPS GeoTiff	 \
		Geotag H264 HTML HP HtmlDump ICC_Profile ID3 IPTC ITC	 \
		InDesign JPEG JPEGDigest JVC Jpeg2000 Kodak KyoceraRaw	 \
		LNK Leaf M2TS MIE MIFF MNG MPC MPEG MPF MWG MakerNotes	 \
		Matroska Minolta MinoltaRaw Nikon NikonCapture		 \
		NikonCustom OOXML Olympus PDF PICT PNG PPM PSP Panasonic \
		PanasonicRaw Pentax PhotoMechanic Photoshop PostScript	 \
		PrintIM QuickTime RIFF RSRC RTF Rawzor Real Ricoh	 \
		Samsung Sanyo Shift Shortcuts Sigma SigmaRaw Sony	 \
		SonyIDC Stim TagInfoXML TagLookup TagNames Unknown	 \
		Vorbis WriteCanonRaw WriteExif WriteIPTC WritePDF	 \
		WritePNG WritePhotoshop WritePostScript WriteXMP Writer	 \
		XMP XMP2 ZIP iWork
LANGTAGS=	cs de en_ca en_gb es fr it ja ko nl pl ru sv tr zh_cn zh_tw

MAN3=		File::RandomAccess.3				\
		Image::ExifTool.3 Image::ExifTool::MIEUnits.3	\
		${MANTAGS:S/^/Image::ExifTool::/:S/$/.3/}	\
		${LANGTAGS:S/^/Image::ExifTool::Lang::/:S/$/.3/}

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
