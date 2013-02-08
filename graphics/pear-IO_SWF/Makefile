# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO_SWF
PORTVERSION=	2.2.2
CATEGORIES=	graphics www pear
MASTER_SITES=	http://openpear.org/get/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	pear-

MAINTAINER=	yoya@awm.jp
COMMENT=	PEAR library for reading/writing SWF binary

LICENSE=	MIT

RUN_DEPENDS=	pear-IO_Bit>0:${PORTSDIR}/devel/pear-IO_Bit \
		${PEARDIR}/.channels/openpear.org.reg:${PORTSDIR}/devel/pear-channel-openpear

USE_PHP=	yes
PEAR_CHANNEL=	openpear

FILES=		IO/SWF.php IO/SWF/ActionEditor.php \
		IO/SWF/Bitmap.php IO/SWF/Decompiler.php \
		IO/SWF/Editor.php IO/SWF/Exception.php \
		IO/SWF/Former.php IO/SWF/JPEG.php \
		IO/SWF/Lossless.php IO/SWF/Tag.php \
		IO/SWF/Tag/Action.php IO/SWF/Tag/BGColor.php \
		IO/SWF/Tag/Base.php IO/SWF/Tag/Button.php \
		IO/SWF/Tag/EditText.php IO/SWF/Tag/Font.php \
		IO/SWF/Tag/FrameLabel.php IO/SWF/Tag/Jpeg.php \
		IO/SWF/Tag/Lossless.php IO/SWF/Tag/Place.php \
		IO/SWF/Tag/Remove.php IO/SWF/Tag/Shape.php \
		IO/SWF/Tag/Sound.php IO/SWF/Tag/Sprite.php \
		IO/SWF/Tag/Text.php IO/SWF/Type.php \
		IO/SWF/Type/Action.php \
		IO/SWF/Type/BUTTONCONDACTION.php \
		IO/SWF/Type/BUTTONRECORD.php \
		IO/SWF/Type/CLIPACTIONRECORD.php \
		IO/SWF/Type/CLIPACTIONS.php \
		IO/SWF/Type/CLIPEVENTFLAGS.php \
		IO/SWF/Type/CXFORM.php \
		IO/SWF/Type/CXFORMWITHALPHA.php \
		IO/SWF/Type/Double.php IO/SWF/Type/FILLSTYLE.php \
		IO/SWF/Type/FILLSTYLEARRAY.php \
		IO/SWF/Type/FILTER.php IO/SWF/Type/FILTERLIST.php \
		IO/SWF/Type/Float.php IO/SWF/Type/GLYPHENTRY.php \
		IO/SWF/Type/KERNINGRECORD.php \
		IO/SWF/Type/LANGCODE.php IO/SWF/Type/LINESTYLE.php \
		IO/SWF/Type/LINESTYLEARRAY.php \
		IO/SWF/Type/MATRIX.php IO/SWF/Type/RECT.php \
		IO/SWF/Type/RGB.php IO/SWF/Type/RGBA.php \
		IO/SWF/Type/SHAPE.php IO/SWF/Type/String.php \
		IO/SWF/Type/TEXTRECORD.php
EXAMPLES=	get_bitmapsize.php jpeg_dump.php \
		swfactioneditor.php swfconvlossless2pngjpeg.php \
		swfcopy.php swfcountshapeedges.php \
		swfdecompile.php swfdeformeshape.php \
		swfdeleteaction.php swfdump.php swfextract.php \
		swfframerate.php swfgeteditstring.php \
		swfgetjpegdata.php swfgetmovieclip.php \
		swfgetpngdata.php swfgetsounddata.php \
		swfgreptags.php swfheader.php swflistaction.php \
		swflistmovieclip.php swfrebuild.php \
		swfreplaceactionstrings.php \
		swfreplacebitmapdata.php swfreplaceeditstring.php \
		swfreplacemovieclip.php swfselectbycids.php \
		swfsetactionvariables.php swfsetbgcolor.php \
		swfsliceshaperecords.php swfwireframe.php
_EXAMPLESDIR=   sample

x-generate-files: extract
	@${FIND} ${WRKSRC}/IO -type f | ${SORT} | ${SED} 's@${WRKSRC}/@@' |\
		${FMT} -50 | ${SED} -e 's@^@		@' -e 's@$$@ \\@'

x-generate-examples: extract
	@${FIND} ${WRKSRC}/sample -type f | ${SORT} | ${SED} 's@${WRKSRC}/sample/@@' |\
		${FMT} -50 | ${SED} -e 's@^@		@' -e 's@$$@ \\@'

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
