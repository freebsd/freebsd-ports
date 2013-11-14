# Created by: Tod McQuillin <devin@spamcop.net>
# $FreeBSD$

PORTNAME=	Image-ExifTool
PORTVERSION=	9.40
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel

MAINTAINER=	linpct@gmail.com
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

CONFLICTS=	p5-Image-ExifTool-[0-9]*

USES=		perl5
USE_PERL5=	configure

MAN1=		exiftool.1
MAN3=		File::RandomAccess.3 Image::ExifTool.3 \
		${MANTAGS:S/^/Image::ExifTool::/:S/$/.3/} \
		${LANGTAGS:S/^/Image::ExifTool::Lang::/:S/$/.3/}

LANGTAGS=	cs de en_ca en_gb es fi fr it ja ko nl pl ru sv tr zh_cn zh_tw
MANTAGS=	AES AFCP AIFF APE APP12 ASF Apple BMP BZZ BigTIFF BuildTagLookup \
		Canon CanonCustom CanonRaw CanonVRD CaptureOne Casio Charset \
		DICOM DNG DPX DV DarwinCore DjVu EXE Exif FLAC FLIR Fixup Flash FlashPix Font \
		FotoStation FujiFilm GE GIF GIMP GPS GeoTiff Geotag H264 HP \
		HTML HtmlDump ICC_Profile ID3 IPTC ITC Import InDesign JPEG \
		JPEGDigest JVC Jpeg2000 Kodak KyoceraRaw LNK Leaf M2TS MIE \
		MIEUnits MIFF MNG MPC MPEG MPF MWG MXF MakerNotes Matroska \
		Microsoft Minolta MinoltaRaw Nikon NikonCapture NikonCustom \
		OOXML Ogg Olympus OpenEXR PDF PGF PICT PLIST PNG PPM PSP Panasonic \
		PanasonicRaw Pentax PhaseOne PhotoCD PhotoMechanic Photoshop PostScript PrintIM \
		Qualcomm QuickTime RIFF RSRC RTF Radiance Rawzor Real Reconyx Ricoh Samsung \
		Sanyo Scalado Shift Shortcuts Sigma SigmaRaw Sony SonyIDC Stim \
		TagInfoXML TagLookup TagNames Theora Torrent Unknown Vorbis \
		WriteCanonRaw WriteExif WriteIPTC WritePDF WritePNG \
		WritePhotoshop WritePostScript WriteQuickTime WriteXMP Writer XMP XMP2 \
		XMPStruct ZIP iWork

NO_STAGE=	yes
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
