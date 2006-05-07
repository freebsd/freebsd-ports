# Ports collection makefile for:  pear-Image-Graph
# Date created:			  01 March 2005
# Whom:				  Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Image_Graph
PORTVERSION=	0.7.1
CATEGORIES=	graphics www pear

MAINTAINER=	nick@foobar.org
COMMENT=	An OO PEAR graph rendering package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log \
		${PEARDIR}/Image/Canvas.php:${PORTSDIR}/graphics/pear-Image_Canvas

CATEGORY=	Image
FILES=		Graph.php Graph/Axis.php Graph/Common.php Graph/Config.php \
		Graph/Constants.php Graph/DataPreprocessor.php \
		Graph/DataSelector.php Graph/Dataset.php  Graph/Element.php \
		Graph/Fill.php Graph/Font.php Graph/Grid.php \
		Graph/Layout.php Graph/Legend.php Graph/Logo.php \
		Graph/Marker.php Graph/Plot.php Graph/Plotarea.php \
		Graph/Simple.php Graph/Title.php Graph/Tool.php \
		Graph/Axis/Category.php Graph/Axis/Logarithmic.php \
		Graph/Axis/Radar.php Graph/Axis/Marker/Area.php \
		Graph/Axis/Marker/Line.php Graph/DataPreprocessor/Array.php \
		Graph/DataPreprocessor/Currency.php \
		Graph/DataPreprocessor/Date.php \
		Graph/DataPreprocessor/Formatted.php \
		Graph/DataPreprocessor/Function.php \
		Graph/DataPreprocessor/NumberText.php \
		Graph/DataPreprocessor/RomanNumerals.php \
		Graph/DataPreprocessor/Sequential.php \
		Graph/Dataset/Function.php Graph/Dataset/Random.php \
		Graph/Dataset/Sequential.php Graph/Dataset/Trivial.php \
		Graph/Dataset/VectorFunction.php \
		Graph/DataSelector/EveryNthPoint.php \
		Graph/DataSelector/NoZeros.php Graph/DataSelector/Values.php \
		Graph/Figure/Circle.php Graph/Figure/Ellipse.php \
		Graph/Figure/Polygon.php Graph/Figure/Rectangle.php \
		Graph/Fill/Array.php Graph/Fill/Gradient.php \
		Graph/Fill/Image.php Graph/Grid/Bars.php \
		Graph/Grid/Lines.php Graph/Grid/Polar.php \
		Graph/Images/Icons/pinpoint.png \
		Graph/Images/Icons/pinpointr.png Graph/Images/Maps/README \
		Graph/Layout/Horizontal.php \
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
		Graph/Marker/Star.php Graph/Marker/Triangle.php \
		Graph/Marker/Value.php Graph/Marker/Pointing/Angular.php \
		Graph/Marker/Pointing/Radial.php Graph/Plot/Area.php \
		Graph/Plot/Band.php Graph/Plot/Bar.php \
		Graph/Plot/BoxWhisker.php Graph/Plot/CandleStick.php \
		Graph/Plot/Dot.php Graph/Plot/Impulse.php \
		Graph/Plot/Line.php Graph/Plot/Odo.php Graph/Plot/Pie.php \
		Graph/Plot/Radar.php Graph/Plot/Step.php \
		Graph/Plot/Fit/Line.php Graph/Plot/Smoothed/Area.php \
		Graph/Plot/Smoothed/Bezier.php Graph/Plot/Smoothed/Line.php \
		Graph/Plot/Smoothed/Radar.php \
		Graph/Plotarea/Element.php Graph/Plotarea/Map.php \
		Graph/Plotarea/Radar.php

TESTS=		freetype.php gd.php README axis/category.php \
		axis/intersection.php axis/intersection_secondary_axis.php \
		axis/inversion.php axis/labelinterval.php \
		axis/logarithmic.php plot/area.php plot/bar.php \
		plot/impulse.php plot/line.php plot/step.php \
		plot/horizontal/area.php plot/horizontal/bar.php \
		plot/horizontal/impulse.php plot/horizontal/line.php \
		plot/horizontal/step.php

DOCS=		ChangeLog colors.txt LICENSE README examples/antialias.php  \
		examples/axis_direction.php \
		examples/category_axis_explanation.php \
		examples/color_chart.php \
		examples/customize.php \
		examples/datapreprocessor.php \
		examples/double_category_axis.php \
		examples/driver_filepdf.php \
		examples/driver_pdf.php \
		examples/driver_png_svg.php \
		examples/driver_swf01.php \
		examples/driver_swf02.php \
		examples/driver_swf03.php \
		examples/frontpage_sample.php \
		examples/gradient_fill_area.php \
		examples/gradient_pie.php \
		examples/horizontal.php \
		examples/gradient_step.php \
		examples/html_image_map.php \
		examples/imagemap.png \
		examples/image_fill.php \
		examples/index.html \
		examples/layout_matrix.php \
		examples/line_break.php \
		examples/logo_graph.php \
		examples/log_axis.php \
		examples/log_axis_intersect.php \
		examples/manual_labels.php \
		examples/misc01.php \
		examples/misc02.php \
		examples/misc03.php \
		examples/misc04.php \
		examples/misc05.php \
		examples/misc06.php \
		examples/multiple_plots.php \
		examples/negative_values.php \
		examples/plot_all.php \
		examples/plot_area.php \
		examples/plot_all_horizontal.php \
		examples/plot_all_horizontal_invert.php \
		examples/plot_area_smooth.php \
		examples/plot_area_stack.php \
		examples/plot_band.php \
		examples/plot_bar.php \
		examples/plot_bar_horizontal.php \
		examples/plot_bar_multiple.php \
		examples/plot_bar_stacked.php \
		examples/plot_bar_stacked100pct.php \
		examples/plot_bar_stacked_horizontal.php \
		examples/plot_bar_stacked_negative.php \
		examples/plot_boxwhisker.php \
		examples/plot_candlestick.php \
		examples/plot_impulse.php \
		examples/plot_line.php \
		examples/plot_impulse_stacked.php \
		examples/plot_line_smooth.php \
		examples/plot_map.php \
		examples/plot_odo.php \
		examples/plot_pie.php \
		examples/plot_pie_rotate.php \
		examples/plot_radar.php \
		examples/plot_radar_smooth.php \
		examples/plot_scatter.php \
		examples/plot_scatter_linefit.php \
		examples/plot_step.php \
		examples/secondary_axis.php \
		examples/simple.php \
		examples/simple_graph.php \
		examples/small_pie_plot.php \
		examples/vector_function.php \
		examples/data/colors.txt \
		examples/images/audi-tt-coupe.jpg \
		examples/images/audi.png \
		examples/images/bmw.png \
		examples/images/coins.png \
		examples/images/mercedes.png \
		examples/images/modify.jpg \
		examples/images/mountain.jpg \
		examples/images/porsche.png

LATEST_LINK=	pear-Image_Graph

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.include <bsd.port.post.mk>
