# Ports collection makefile for:  pear-Image-Graph
# Date created:			  01 March 2005
# Whom:				  Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Image_Graph
PORTVERSION=	0.3.0
CATEGORIES=	graphics www pear

MAINTAINER=	nick@foobar.org
COMMENT=	An OO PEAR graph rendering package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${PEARDIR}/Image/Color.php:${PORTSDIR}/graphics/pear-Image_Color \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log

# TODO: add PDFLIB support as soon as the FreeBSD port of PHP supports it

USE_PHP=	gd ming
USE_REINPLACE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

CATEGORY=	Image
FILES=		Graph.php Graph/Axis.php Graph/Color.php \
		Graph/Common.php Graph/Config.php Graph/Constants.php \
		Graph/DataPreprocessor.php Graph/DataSelector.php \
		Graph/Dataset.php Graph/Driver.php Graph/Element.php \
		Graph/Fill.php Graph/Font.php Graph/Grid.php \
		Graph/Layout.php Graph/Legend.php Graph/Logo.php \
		Graph/Marker.php Graph/Plot.php Graph/Plotarea.php \
		Graph/Simple.php Graph/Title.php Graph/Tool.php \
		Graph/Axis/Category.php Graph/Axis/Logarithmic.php \
		Graph/Axis/Radar.php Graph/Axis/Marker/Area.php \
		Graph/Axis/Marker/Line.php \
		Graph/DataPreprocessor/Array.php \
		Graph/DataPreprocessor/Currency.php \
		Graph/DataPreprocessor/Date.php \
		Graph/DataPreprocessor/Formatted.php \
		Graph/DataPreprocessor/Function.php \
		Graph/DataPreprocessor/NumberText.php \
		Graph/DataPreprocessor/RomanNumerals.php \
		Graph/DataPreprocessor/Sequential.php \
		Graph/DataSelector/EveryNthPoint.php \
		Graph/DataSelector/NoZeros.php Graph/Dataset/Function.php \
		Graph/Dataset/Random.php Graph/Dataset/Sequential.php \
		Graph/Dataset/Trivial.php Graph/Dataset/VectorFunction.php \
		Graph/Driver/GD.php Graph/Driver/PDFlib.php \
		Graph/Driver/SVG.php Graph/Driver/SWF.php \
		Graph/Driver/GD/GIF.php Graph/Driver/GD/JPG.php \
		Graph/Driver/GD/PNG.php Graph/Driver/GD/WBMP.php \
		Graph/Figure/Circle.php Graph/Figure/Ellipse.php \
		Graph/Figure/Polygon.php Graph/Figure/Rectangle.php \
		Graph/Fill/Array.php Graph/Fill/Gradient.php \
		Graph/Fill/Image.php Graph/Font/Extended.php \
		Graph/Font/TTF.php Graph/Font/Vertical.php \
		Graph/Grid/Bars.php Graph/Grid/Lines.php \
		Graph/Grid/Polar.php Graph/Layout/Horizontal.php \
		Graph/Layout/Matrix.php Graph/Layout/Vertical.php \
		Graph/Line/Array.php Graph/Line/Dashed.php \
		Graph/Line/Dotted.php Graph/Line/Formatted.php \
		Graph/Line/Solid.php Graph/Marker/Array.php \
		Graph/Marker/Asterisk.php Graph/Marker/Average.php \
		Graph/Marker/Box.php Graph/Marker/Bubble.php \
		Graph/Marker/Circle.php Graph/Marker/Cross.php \
		Graph/Marker/Diamond.php Graph/Marker/Icon.php \
		Graph/Marker/Pinpoint.php Graph/Marker/Plus.php \
		Graph/Marker/Pointing.php Graph/Marker/ReversePinpoint.php \
		Graph/Marker/Triangle.php Graph/Marker/Value.php \
		Graph/Marker/Pointing/Angular.php \
		Graph/Marker/Pointing/Radial.php Graph/Plot/Area.php \
		Graph/Plot/Band.php Graph/Plot/Bar.php \
		Graph/Plot/BoxWhisker.php Graph/Plot/CandleStick.php \
		Graph/Plot/Dot.php Graph/Plot/Impulse.php \
		Graph/Plot/Line.php Graph/Plot/Pie.php \
		Graph/Plot/Radar.php Graph/Plot/Step.php \
		Graph/Plot/Smoothed/Area.php \
		Graph/Plot/Smoothed/Bezier.php \
		Graph/Plot/Smoothed/Line.php Graph/Plot/Smoothed/Radar.php \
		Graph/Plotarea/Element.php Graph/Plotarea/Map.php \
		Graph/Plotarea/Radar.php \
		Graph/Fonts/fontmap.txt

TESTS=		freetype.php gd.php README axis/category.php \
		axis/intersection.php axis/intersection_secondary_axis.php \
		axis/inversion.php axis/labelinterval.php \
		axis/logarithmic.php driver/driver_body.php driver/gif.php \
		driver/gradients.php driver/jpg.php driver/pear-icon.png \
		driver/png.php driver/svg.php driver/text.php \
		driver/wbmp.php plot/area.php plot/bar.php plot/impulse.php \
		plot/line.php plot/step.php

DOCS=		ChangeLog colors.txt Drivers.txt LICENSE README examples/barchart1.php \
		examples/drivers1.php examples/drivers2.php examples/linechart1.php \
		examples/piechart1.php examples/images/audi.png examples/images/bmw.png \
		examples/images/coins.png examples/images/mercedes.png \
		examples/images/porsche.png

FONTDIR=	${PEARDIR}/${CATEGORY}/Graph/Fonts

PLIST_FILES+=	share/pear/${CATEGORY}/Graph/Fonts/fontmap.txt-dist
LATEST_LINK=	pear-Image_Graph

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

post-install-script:
	@${CP} ${WRKSRC}/Graph/Fonts/fontmap.txt ${FONTDIR}/fontmap.txt-dist
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
