# New ports collection makefile for:	p5-Image-ExifTool
# Date Created:				15 Sep 2004
# Whom:					Tod McQuillin <devin@spamcop.net>
#
# $FreeBSD$
#

PORTNAME=	Image-ExifTool
PORTVERSION=	8.65
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel

MAINTAINER=	linpct@gmail.com
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

CONFLICTS=	p5-Image-ExifTool-[0-9]*

PERL_CONFIGURE=	yes

MAN1=		exiftool.1
MAN3=		File::RandomAccess.3 Image::ExifTool.3 \
		${MANTAGS:S/^/Image::ExifTool::/:S/$/.3/} \
		${LANGTAGS:S/^/Image::ExifTool::Lang::/:S/$/.3/}

LANGTAGS=	cs de en_ca en_gb es fr it ja ko nl pl ru sv tr zh_cn zh_tw
MANTAGS=	AES AFCP AIFF APE APP12 ASF BMP BZZ BigTIFF BuildTagLookup \
		Canon CanonCustom CanonRaw CanonVRD CaptureOne Casio Charset \
		DICOM DNG DV DjVu EXE Exif FLAC Fixup Flash FlashPix Font \
		FotoStation FujiFilm GE GIF GIMP GPS GeoTiff Geotag H264 HP \
		HTML HtmlDump ICC_Profile ID3 IPTC ITC Import InDesign JPEG \
		JPEGDigest JVC Jpeg2000 Kodak KyoceraRaw LNK Leaf M2TS MIE \
		MIEUnits MIFF MNG MPC MPEG MPF MWG MXF MakerNotes Matroska \
		Microsoft Minolta MinoltaRaw Nikon NikonCapture NikonCustom \
		OOXML Ogg Olympus PDF PGF PICT PNG PPM PSP Panasonic \
		PanasonicRaw Pentax PhotoMechanic Photoshop PostScript PrintIM \
		QuickTime RIFF RSRC RTF Rawzor Real Reconyx Ricoh Samsung \
		Sanyo Shift Shortcuts Sigma SigmaRaw Sony SonyIDC Stim \
		TagInfoXML TagLookup TagNames Theora Unknown Vorbis \
		WriteCanonRaw WriteExif WriteIPTC WritePDF WritePNG \
		WritePhotoshop WritePostScript WriteXMP Writer XMP XMP2 \
		XMPStruct ZIP iWork

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/*.css ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/*.pdf ${DOCSDIR}/
	@${MKDIR} ${DOCSDIR}/TagNames/
	${INSTALL_DATA} ${WRKSRC}/html/TagNames/*.html ${DOCSDIR}/TagNames/
.endif

.include <bsd.port.mk>
