# New ports collection makefile for:	phplot
# Date created:         21 Oct 2001
# Whom:                 yukinopo@livedoor.com
#
# $FreeBSD$

PORTNAME=	phplot
PORTVERSION=	5.0.6
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}docs-20090121.zip

MAINTAINER=	yukinopo@livedoor.com
COMMENT=	A PHP class for creating scientific and business charts

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

USE_ZIP=	yes
USE_PHP=	yes
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
NO_BUILD=	YES

PHPLOT_DIR=	${PREFIX}/include/php/phplot

LIBS=		phplot.php phplot_data.php rgb.inc.php

DOCS=		DrawGraph.html GetCallback.html PHPlot.html PrintImage.html \
		RemoveCallback.html SetBackgroundColor.html SetBgImage.html \
		SetBrowserCache.html SetCallback.html SetDataBorderColors.html \
		SetDataColors.html SetDataType.html SetDataValues.html \
		SetDefaultDashedStyle.html SetDefaultTTFont.html SetDrawBrokenLines.html \
		SetDrawDashedGrid.html SetDrawPlotAreaBackground.html \
		SetDrawXDataLabelLines.html SetDrawXGrid.html SetDrawYDataLabelLines.html \
		SetDrawYGrid.html SetErrorBarColors.html SetErrorBarLineWidth.html \
		SetErrorBarShape.html SetErrorBarSize.html SetFileFormat.html \
		SetFont.html SetGridColor.html SetImageBorderColor.html SetImageBorderType.html \
		SetIsInline.html SetLabelColor.html SetLabelScalePosition.html SetLegend.html \
		SetLegendPixels.html SetLegendStyle.html SetLegendWorld.html SetLightGridColor.html \
		SetLineSpacing.html SetLineStyles.html SetLineWidths.html SetMarginsPixels.html \
		SetNumXTicks.html SetNumYTicks.html SetNumberFormat.html SetOutputFile.html \
		SetPlotAreaBgImage.html SetPlotAreaPixels.html SetPlotAreaWorld.html \
		SetPlotBgColor.html SetPlotBorderType.html SetPlotType.html SetPointShapes.html \
		SetPointSizes.html SetPrecisionX.html SetPrecisionY.html SetPrintImage.html \
		SetRGBArray.html SetShading.html SetSkipBottomTick.html SetSkipLeftTick.html \
		SetSkipRightTick.html SetSkipTopTick.html SetTTFPath.html SetTextColor.html \
		SetTickColor.html SetTitle.html SetTitleColor.html SetTransparentColor.html \
		SetUseTTF.html SetXAxisPosition.html SetXDataLabelPos.html SetXLabelAngle.html \
		SetXLabelType.html SetXScaleType.html SetXTickCrossing.html SetXTickIncrement.html \
		SetXTickLabelPos.html SetXTickLength.html SetXTickPos.html SetXTimeFormat.html \
		SetXTitle.html SetYAxisPosition.html SetYDataLabelPos.html SetYLabelAngle.html \
		SetYLabelType.html SetYScaleType.html SetYTickCrossing.html SetYTickIncrement.html \
		SetYTickLabelPos.html SetYTickLength.html SetYTickPos.html SetYTimeFormat.html \
		SetYTitle.html callbacks-access.html callbacks-names.html callbacks-objects.html \
		callbacks.html changelog.html conc-colors.html conc-datatypes.html \
		conc-errors.html conc-extradata.html conc-labels.html conc-overview.html \
		conc-plottypes.html concepts.html dev-internal.html dev-layout.html dev-legend.html \
		ex-area1.html ex-bars1.html ex-bars2.html ex-bars3.html ex-bars4.html ex-linepoints1.html \
		ex-lines2.html ex-pie1.html ex-pie2.html ex-pie3.html ex-points1.html ex-points2.html \
		ex-squared1.html ex-stackedbars1.html ex-stackedbars2.html ex-thinbarline1.html \
		ex-thinbarline2.html ex-twoplot1.html examples.html functions.html index.html \
		install-install.html install-next.html install.html part1.html part3.html \
		phplotdoc.css preface.html ref-addlstyle.html ref-axes.html ref-callbacks.html \
		ref-colorstyle.html ref-errorbars.html ref-grid.html ref-iocontrol.html \
		ref-labels.html ref-legend.html ref-scaling.html ref-textfonts.html ref-ticks.html \
		ref-titles.html reference.html start-multiple.html starting-create.html \
		starting-custom.html starting-more.html starting-next.html starting-simple.html \
		starting.html

EXAMPLES=	area1.png bars1.png bars2.png bars3.png bars4.png linepoints1.png lines1.png \
		lines2.png pie1.png pie2.png pie3.png points1.png points2.png qs1.png qs2.png \
		qs3.png squared1.png stackedbars1.png stackedbars2.png thinbarline1.png \
		thinbarline2.png twoplot1.png

IMAGES=		colors.png error-image.png fonts.png gdinfo.png labels-pie.png labels.png \
		layout.png legend-layout.png legendstyle.png ticksize.png typical-grid.png \
		typical-legend.png typical-titles.png

OPTIONS=	FONTS "Install TrueType fonts" on

.if defined(WITH_FONTS)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif

do-install:
	@${MKDIR} ${PHPLOT_DIR}
	@${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/,} ${PHPLOT_DIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKDIR}/phplotdocs/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/images
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKDIR}/phplotdocs/examples/,} ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${IMAGES:S,^,${WRKDIR}/phplotdocs/images/,} ${EXAMPLESDIR}/images/
.endif

.include <bsd.port.mk>
