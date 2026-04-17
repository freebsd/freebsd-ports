/**
 * JKQtPlotter examples-all: A tab widget showing all major examples
 */

#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <random>
#include <cmath>

#include "jkqtplotter/jkqtplotter.h"
#include "jkqtcommon/jkqtpmathtools.h"
#include "jkqtcommon/jkqtpstringtools.h"
#include "jkqtplotter/jkqtptools.h"
#include "jkqtplotter/jkqtpcoordinateaxes.h"
#include "jkqtplotter/graphs/jkqtplines.h"
#include "jkqtplotter/graphs/jkqtpscatter.h"
#include "jkqtplotter/graphs/jkqtpbarchart.h"
#include "jkqtplotter/graphs/jkqtpboxplot.h"
#include "jkqtplotter/graphs/jkqtpcontour.h"
#include "jkqtplotter/graphs/jkqtpevaluatedparametriccurve.h"
#include "jkqtplotter/graphs/jkqtpfilledcurve.h"
#include "jkqtplotter/graphs/jkqtpgraphlabels.h"
#include "jkqtplotter/graphs/jkqtpimage.h"
#include "jkqtplotter/graphs/jkqtpimpulses.h"
#include "jkqtplotter/graphs/jkqtpgeometric.h"
#include "jkqtplotter/graphs/jkqtpviolinplot.h"
#include "jkqtplotter/graphs/jkqtpsinglecolumnsymbols.h"
#include "jkqtplotter/graphs/jkqtpstatisticsadaptors.h"
#include "jkqtplotter/graphs/jkqtpvectorfield.h"
#include "jkqtmath/jkqtpstatbasics.h"
#include "jkqtmath/jkqtpstatkde.h"
#include "jkqtmath/jkqtpstathistogram.h"


// 1. Simple sine wave (simpletest)
void setup_simpletest(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    QVector<double> X, Y;
    const int Ndata = 100;
    for (int i = 0; i < Ndata; i++) {
        const double x = double(i) / double(Ndata) * 8.0 * JKQTPSTATISTICS_PI;
        X << x;
        Y << sin(x);
    }
    size_t columnX = ds->addCopiedColumn(X, "x");
    size_t columnY = ds->addCopiedColumn(Y, "y");

    JKQTPXYLineGraph* graph1 = new JKQTPXYLineGraph(plot);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setTitle(QObject::tr("sine graph"));
    plot->addGraph(graph1);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Simple Test"));
}


// 2. Scatter graph with noise (scatter)
void setup_scatter(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    size_t columnX = ds->addColumn("x");
    auto colXInserter = ds->backInserter(columnX);
    size_t columnY = ds->addColumn("y");
    auto colYInserter = ds->backInserter(columnY);

    std::default_random_engine generator(123);
    std::normal_distribution<double> distribution(0, 0.5);
    const int Ndata = 100;
    for (int i = 0; i < Ndata; i++) {
        const double x = double(i) / double(Ndata) * 8.0 * JKQTPSTATISTICS_PI;
        *colXInserter = x;
        *colYInserter = sin(x) + distribution(generator);
        colXInserter++;
        colYInserter++;
    }

    JKQTPXYScatterGraph* graph1 = new JKQTPXYScatterGraph(plot);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setTitle(QObject::tr("sine graph"));
    plot->addGraph(graph1);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Scatter Example"));
}


// 3. Bar chart (barchart)
void setup_barchart(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    const int Ndata = 5;
    QString L[Ndata] = {"cat. A", "cat. C", "cat. B", "cat. D", "other"};
    double  X[Ndata] = {1, 3, 2, 4, 5};
    double Y1[Ndata] = {5, 4, 3, 4, 5};
    double Y2[Ndata] = {-5, -3, 1, 3, 6};
    double Y3[Ndata] = {6, 2, 5, 3, 6};

    size_t columnX  = ds->addCopiedColumn(X, Ndata, "x");
    size_t columnY1 = ds->addCopiedColumn(Y1, Ndata, "y1");
    size_t columnY2 = ds->addCopiedColumn(Y2, Ndata, "y2");
    size_t columnY3 = ds->addCopiedColumn(Y3, Ndata, "y3");

    JKQTPBarVerticalGraph* graph1 = new JKQTPBarVerticalGraph(plot);
    graph1->setBarPositionColumn(columnX);
    graph1->setBarHeightColumn(columnY1);
    graph1->setTitle(QObject::tr("dataset 1"));
    JKQTPBarVerticalGraph* graph2 = new JKQTPBarVerticalGraph(plot);
    graph2->setBarPositionColumn(columnX);
    graph2->setBarHeightColumn(columnY2);
    graph2->setTitle(QObject::tr("dataset 2"));
    JKQTPBarVerticalGraph* graph3 = new JKQTPBarVerticalGraph(plot);
    graph3->setBarPositionColumn(columnX);
    graph3->setBarHeightColumn(columnY3);
    graph3->setTitle(QObject::tr("dataset 3"));

    plot->addGraph(graph1);
    plot->addGraph(graph2);
    plot->addGraph(graph3);
    graph1->autoscaleBarWidthAndShift();

    plot->getXAxis()->addAxisTickLabels(X, L, Ndata);
    plot->getXAxis()->setTickLabelAngle(45);
    plot->getXAxis()->setTickLabelFontSize(12);
    plot->getPlotter()->setKeyPosition(JKQTPKeyOutsideTopRight);
    plot->getMainKey()->setLayout(JKQTPKeyLayoutOneRow);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Bar Chart"));
}


// 4. Box plots (boxplot)
void setup_boxplot(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    QVector<double> POS, POSY, MEDIAN, MEAN, Q25, Q75, MIN, MAX, OUTLIERSX, OUTLIERSY;
    POS    << 1   << 4   << 7   << 10;
    POSY   << -1  << -2  << -3  << -4;
    MIN    << 2   << 3   << 2.5 << 6;
    Q25    << 4   << 4.5 << 5   << 7;
    MEDIAN << 5   << 6   << 7   << 9;
    MEAN   << 5.5 << 5.2 << 8   << 8;
    Q75    << 6   << 7   << 9   << 11;
    MAX    << 8   << 7.5 << 11  << 12;
    OUTLIERSX << 4 << 4   << 4   << 4 << 4      << 10 << 10 << 10   << 10 << 10   << 10   << 10;
    OUTLIERSY << 1 << 0.5 << 1.3 << 8 << 8.1    << 5  << 4  << 12.2 << 13 << 12.5 << 13.5 << 13.1;

    size_t columnPOS      = ds->addCopiedColumn(POS,      "POS");
    size_t columnPOSY     = ds->addCopiedColumn(POSY,     "POSY");
    size_t columnMIN      = ds->addCopiedColumn(MIN,      "MIN");
    size_t columnQ25      = ds->addCopiedColumn(Q25,      "Q25");
    size_t columnMEDIAN   = ds->addCopiedColumn(MEDIAN,   "MEDIAN");
    size_t columnMEAN     = ds->addCopiedColumn(MEAN,     "MEAN");
    size_t columnQ75      = ds->addCopiedColumn(Q75,      "Q75");
    size_t columnMAX      = ds->addCopiedColumn(MAX,      "MAX");
    size_t columnOUTLIERSX = ds->addCopiedColumn(OUTLIERSX, "OUTLIERSX");
    size_t columnOUTLIERSY = ds->addCopiedColumn(OUTLIERSY, "OUTLIERSY");

    JKQTPBoxplotVerticalGraph* graph = new JKQTPBoxplotVerticalGraph(plot);
    graph->setPositionColumn(columnPOS);
    graph->setMinColumn(columnMIN);
    graph->setPercentile25Column(columnQ25);
    graph->setMedianColumn(columnMEDIAN);
    graph->setMeanColumn(columnMEAN);
    graph->setPercentile75Column(columnQ75);
    graph->setMaxColumn(columnMAX);
    graph->setTitle("vertical Boxplots");

    JKQTPXYLineGraph* graphOutliers = new JKQTPXYLineGraph(plot);
    graphOutliers->setXColumn(columnOUTLIERSX);
    graphOutliers->setYColumn(columnOUTLIERSY);
    graphOutliers->setTitle("outliers");
    graphOutliers->setColor(graph->getLineColor().darker());
    graphOutliers->setSymbolFillColor(QColor("white"));
    graphOutliers->setSymbolType(JKQTPCircle);
    graphOutliers->setDrawLine(false);
    graphOutliers->setSymbolSize(7);

    JKQTPBoxplotHorizontalGraph* graphh = new JKQTPBoxplotHorizontalGraph(plot);
    graphh->setPositionColumn(columnPOSY);
    graphh->setMinColumn(columnMIN);
    graphh->setPercentile25Column(columnQ25);
    graphh->setMedianColumn(columnMEDIAN);
    graphh->setMeanColumn(columnMEAN);
    graphh->setPercentile75Column(columnQ75);
    graphh->setMaxColumn(columnMAX);
    graphh->setTitle("horizontal Boxplots");
    graphh->setFillColor(graphh->getLineColor().lighter());
    graphh->setWhiskerLineStyle(Qt::DashLine);
    graphh->setWhiskerLineColor(graphh->getLineColor().darker());
    graphh->setWhiskerCapLineStyle(Qt::SolidLine);
    graphh->setWhiskerCapLineColor(graphh->getLineColor().darker());
    graphh->setWhiskerCapLineWidth(graphh->getLineWidth() * 2.5);
    graphh->setMeanSymbolType(JKQTPFilledStar);
    graphh->setMeanFillColor(QColor("silver"));
    graphh->setMedianLineColor(QColor("darkgreen"));
    graphh->setBoxWidthRelative(0.75);

    plot->addGraph(graph);
    plot->addGraph(graphOutliers);
    plot->addGraph(graphh);
    plot->zoomToFit();
    plot->getPlotter()->setKeyPosition(JKQTPKeyInsideTopLeft);
    plot->getPlotter()->setPlotLabel(QObject::tr("Box Plots"));
}


// 5. Contour plot of quadrupole electric potential (contourplot)
void setup_contourplot(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);

    JKQTPDatastore* ds = plot->getDatastore();
    const int NX = 200;
    const int NY = 200;
    const double w = 2.7e-6;
    const double dx = w / static_cast<double>(NX);
    const double h = NY * dx;
    size_t cPotential = ds->addImageColumn(NX, NY, "imagedata");

    double y = -h / 2.0;
    const double eps0  =  8.854187e-12;
    const double Q1    =  1.6e-19,  Q1_x0 = -0.5e-6, Q1_y0 = -0.5e-6;
    const double Q2    =  1.6e-19,  Q2_x0 =  0.5e-6, Q2_y0 =  0.5e-6;
    const double Q3    = -1.6e-19,  Q3_x0 = -0.5e-6, Q3_y0 =  0.5e-6;
    const double Q4    = -1.6e-19,  Q4_x0 =  0.5e-6, Q4_y0 = -0.5e-6;
    for (size_t iy = 0; iy < NY; iy++) {
        double x = -w / 2.0;
        for (size_t ix = 0; ix < NX; ix++) {
            const double r1 = sqrt((x-Q1_x0)*(x-Q1_x0) + (y-Q1_y0)*(y-Q1_y0));
            const double r2 = sqrt((x-Q2_x0)*(x-Q2_x0) + (y-Q2_y0)*(y-Q2_y0));
            const double r3 = sqrt((x-Q3_x0)*(x-Q3_x0) + (y-Q3_y0)*(y-Q3_y0));
            const double r4 = sqrt((x-Q4_x0)*(x-Q4_x0) + (y-Q4_y0)*(y-Q4_y0));
            ds->setPixel(cPotential, ix, iy,
                Q1 / (4.0*JKQTPSTATISTICS_PI*eps0) / r1 +
                Q2 / (4.0*JKQTPSTATISTICS_PI*eps0) / r2 +
                Q3 / (4.0*JKQTPSTATISTICS_PI*eps0) / r3 +
                Q4 / (4.0*JKQTPSTATISTICS_PI*eps0) / r4);
            x += dx;
        }
        y += dx;
    }

    JKQTPColumnContourPlot* graph = new JKQTPColumnContourPlot(plot);
    graph->setTitle("");
    graph->setImageColumn(cPotential);
    graph->setX(-w / 2.0);
    graph->setY(-h / 2.0);
    graph->setWidth(w);
    graph->setHeight(h);
    graph->setColorPalette(JKQTPMathImageBlueGreenRed);
    graph->getColorBarRightAxis()->setAxisLabel("electric potential [V]");

    QVector<double> reldists; reldists << 0.1 << 0.25 << 0.5 << 1 << 1.5 << 2 << 2.5 << 3;
    for (auto reldist : reldists) {
        const double level = fabs(Q1 / (4.0*JKQTPSTATISTICS_PI*eps0) / (Q1_x0 * reldist));
        graph->addContourLevel(-level);
        graph->addContourLevel(level);
    }
    graph->setAutoImageRange(false);
    graph->setImageMin(graph->getContourLevels().first());
    graph->setImageMax(graph->getContourLevels().last());

    plot->addGraph(graph);
    plot->getXAxis()->setAxisLabel("x [m]");
    plot->getYAxis()->setAxisLabel("y [m]");
    plot->getPlotter()->setMaintainAspectRatio(true);
    plot->getPlotter()->setAspectRatio(w / h);
    plot->getPlotter()->setMaintainAxisAspectRatio(true);
    plot->getPlotter()->setAxisAspectRatio(w / h);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Contour Plot"));
}


// 6. Error bar styles (errorbarstyles)
void setup_errorbarstyles(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    QVector<double> X, Yerror, Xerror;
    const int Ndata = 7;
    for (int i = 0; i < Ndata; i++) {
        const double x = 10.0 + double(i) * 2.0;
        X << x;
        Yerror << 0.35 + 0.3 * sin(x);
        Xerror << 0.35 + 0.3 * sin(x);
    }
    size_t columnX      = ds->addCopiedColumn(X,      "x");
    size_t columnXError = ds->addCopiedColumn(Xerror,  "xerror");
    size_t columnYError = ds->addCopiedColumn(Yerror,  "yerror");

    QVector<JKQTPErrorPlotstyle> errorStyles {
        JKQTPNoError, JKQTPErrorBars, JKQTPErrorSimpleBars, JKQTPErrorLines,
        JKQTPErrorPolygons, JKQTPErrorBoxes, JKQTPErrorEllipses,
        JKQTPErrorBarsPolygons, JKQTPErrorBarsLines,
        JKQTPErrorSimpleBarsLines, JKQTPErrorSimpleBarsPolygons
    };
    QVector<bool> showXandYError {
        false, true, true, false, false, true, true, false, false, false, false
    };

    for (int errorID = 0; errorID < errorStyles.size(); errorID++) {
        QVector<double> Y;
        for (auto& xx : X)
            Y << xx * 0.5 + static_cast<double>(errorID) * 2.5;

        JKQTPXYLineErrorGraph* graph = new JKQTPXYLineErrorGraph(plot);
        graph->setXColumn(columnX);
        graph->setYColumn(ds->addCopiedColumn(Y, "y" + QString::number(errorID)));
        graph->setXErrorColumn(columnXError);
        graph->setYErrorColumn(columnYError);
        graph->setYErrorStyle(errorStyles[errorID]);
        graph->setXErrorStyle(JKQTPNoError);
        if (showXandYError[errorID]) {
            graph->setXErrorStyle(errorStyles[errorID]);
            graph->setDrawLine(false);
        }
        QColor c = graph->getErrorFillColor();
        c.setAlphaF(0.3);
        graph->setErrorFillColor(c);
        graph->setErrorLineWidth(1);
        graph->setErrorBarCapSize(15);
        graph->setSymbolType(JKQTPCross);
        graph->setLineStyle(Qt::DashLine);
        graph->setSymbolSize(5);
        graph->setSymbolLineWidth(1);
        graph->setLineWidth(1);
        graph->setTitle("\\verb!" + JKQTPErrorPlotstyle2String(errorStyles[errorID]) + "!");
        plot->addGraph(graph);
    }

    plot->zoomToFit();
    plot->getPlotter()->setKeyPosition(JKQTPKeyOutsideRightTop);
    plot->getXAxis()->setDrawGrid(false);
    plot->getXAxis()->setDrawMinorGrid(false);
    plot->getYAxis()->setDrawGrid(false);
    plot->getYAxis()->setDrawMinorGrid(false);
    plot->getPlotter()->setPlotLabel(QObject::tr("Error Bar Styles"));
}


// 7. Evaluated parametric curves — butterfly curve (evalcurve)
void setup_evalcurve(JKQTPlotter* plot)
{
    JKQTPXYFunctionLineGraph* func1 = new JKQTPXYFunctionLineGraph(plot);
    func1->setPlotFunctionFunctor([](double t) -> QPointF {
        return QPointF(
            sin(t) * (exp(cos(t)) - 2.0*cos(4.0*t) - jkqtp_pow5(sin(t/12.0))),
            cos(t) * (exp(cos(t)) - 2.0*cos(4.0*t) - jkqtp_pow5(sin(t/12.0)))
        );
    });
    func1->setTRange(0, 12.0 * JKQTPSTATISTICS_PI);
    func1->setTitle("C++-inline function: \"Butterfly Curve\"");
    plot->addGraph(func1);

    JKQTPXYFunctionLineGraph* func2 = new JKQTPXYFunctionLineGraph(plot);
    func2->setPlotFunctionFunctor([](double t, const QVector<double>& params) -> QPointF {
        return QPointF(
            3.0*sin(params[0]*t + params[2]) + 8.0,
            3.0*sin(params[1]*t)
        );
    });
    func2->setParamsV(5, 4, JKQTPSTATISTICS_PI / 4.0);
    func2->setTRange(0, 2.0 * JKQTPSTATISTICS_PI);
    func2->setTitle("C++-inline function $[ sin(5{\\cdot}t+\\pi/4), sin(4{\\cdot}t) ]$");
    plot->addGraph(func2);

    plot->getXAxis()->setAxisLabel(QObject::tr("x-axis"));
    plot->getYAxis()->setAxisLabel(QObject::tr("y-axis"));
    plot->getPlotter()->setKeyPosition(JKQTPKeyOutsideBottomLeft);
    plot->setXY(-3, 12, -3.2, 3.2);
    plot->getPlotter()->setPlotLabel(QObject::tr("Parametric Curves (Butterfly)"));
}


// 8. Filled curve graph with sine waves (filledgraphs — adapted, no image resource)
void setup_filledgraphs(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    size_t columnX  = ds->addLinearColumn(256, 0.0, 2.0*JKQTPSTATISTICS_PI, "x");
    size_t columnY1 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return sin(x); },      "sin(x)");
    size_t columnY2 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return cos(x); },      "cos(x)");
    size_t columnY3 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return 0.5*sin(2*x); }, "0.5*sin(2x)");

    auto makeGraph = [&](size_t colY, const QString& title, const QString& colorName) {
        JKQTPFilledCurveXGraph* g = new JKQTPFilledCurveXGraph(plot);
        g->setXColumn(columnX);
        g->setYColumn(colY);
        g->setTitle(title);
        QColor col = QColor(colorName);
        g->setColor(col);
        col.setAlphaF(0.35f);
        g->setFillColor(col);
        g->setLineWidth(1);
        plot->addGraph(g);
    };

    makeGraph(columnY1, "sin(x)",       "red");
    makeGraph(columnY2, "cos(x)",       "blue");
    makeGraph(columnY3, "0.5·sin(2x)", "green");

    plot->getXAxis()->setAxisLabel("x");
    plot->getYAxis()->setAxisLabel("f(x)");
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Filled Curves"));
}


// 9. Graph labels on a bar chart (graphlabels)
void setup_graphlabels(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    const int Ndata = 6;
    const size_t columnX = ds->addLinearColumn(Ndata, -1, 1, "x");
    const size_t columnY = ds->addCalculatedColumnFromColumn(columnX,
        [](double x) { return jkqtp_roundToDigits(-sin(x*3.0), 2); }, "data");

    JKQTPBarVerticalGraph* graph1 = new JKQTPBarVerticalGraph(plot);
    graph1->setBarPositionColumn(columnX);
    graph1->setBarHeightColumn(columnY);
    graph1->setTitle(QObject::tr("dataset: bars"));
    graph1->setColor(QColorWithAlphaF(graph1->getFillColor(), 0.25));

    JKQTPXYLineGraph* graph2 = new JKQTPXYLineGraph(plot);
    graph2->setXColumn(columnX);
    graph2->setYColumn(columnY);
    graph2->setTitle(QObject::tr("dataset: lines"));
    graph2->setColor(QColorWithAlphaF(graph2->getLineColor(), 0.5));

    JKQTPXYGraphLabels* graphLabels = new JKQTPXYGraphLabels(JKQTPXYGraphLabels::YValueLabel, plot);
    graphLabels->setXColumn(graph1->getXColumn());
    graphLabels->setYColumn(graph1->getYColumn());
    graphLabels->setLabelPosition(JKQTPGLabelAwayFromXAxis);
    graphLabels->setTextFontSize(14);

    plot->addGraph(graph1);
    plot->addGraph(graph2);
    plot->addGraph(graphLabels);

    plot->setXY(-1.5, 1.5, -1.5, 1.5);
    plot->getXAxis()->setDrawMode1(JKQTPCADMLine);
    plot->getXAxis()->setDrawMode2(JKQTPCADMLine);
    plot->getYAxis()->setDrawMode1(JKQTPCADMLine);
    plot->getYAxis()->setDrawMode2(JKQTPCADMLine);
    plot->getPlotter()->setPlotLabel(QObject::tr("Graph Labels"));
}


// 10. Image plot — Airy disk (imageplot)
void setup_imageplot(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    const int NX = 100, NY = 100;
    const double dx = 1e-2, dy = 1e-2;
    const double w = static_cast<double>(NX) * dx;
    const double h = static_cast<double>(NY) * dy;
    double airydisk[NX * NY];

    const double NA = 1.1;
    const double wavelength = 488e-3;

    double y = -h / 2.0;
    for (int iy = 0; iy < NY; iy++) {
        double x = -w / 2.0;
        for (int ix = 0; ix < NX; ix++) {
            const double r = sqrt(x*x + y*y);
            const double v = 2.0 * JKQTPSTATISTICS_PI * NA * r / wavelength;
            airydisk[iy*NX + ix] = pow(2.0 * jkqtp_j1(v) / v, 2);
            x += dx;
        }
        y += dy;
    }

    size_t cAiryDisk = ds->addCopiedImageAsColumn(airydisk, NX, NY, "imagedata");

    JKQTPColumnMathImage* graph = new JKQTPColumnMathImage(plot);
    graph->setTitle("");
    graph->setImageColumn(cAiryDisk);
    graph->setNx(NX);
    graph->setNy(NY);
    graph->setX(-w / 2.0);
    graph->setY(-h / 2.0);
    graph->setWidth(w);
    graph->setHeight(h);
    graph->setColorPalette(JKQTPMathImageMATLAB);
    graph->getColorBarRightAxis()->setAxisLabel("light intensity [A.U.]");
    graph->setAutoImageRange(true);

    plot->addGraph(graph);
    plot->getXAxis()->setAxisLabel("x [{\\mu}m]");
    plot->getYAxis()->setAxisLabel("y [{\\mu}m]");
    plot->getPlotter()->setMaintainAspectRatio(true);
    plot->getPlotter()->setMaintainAxisAspectRatio(true);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Image Plot (Airy Disk)"));
}


// 11. Impulse graph (impulsesplot)
void setup_impulsesplot(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    const int NData = 40;
    QVector<double> X, Y, E;
    for (int i = 0; i < NData; i++) {
        const double xx = double(i) / 40.0 * 8.0 * JKQTPSTATISTICS_PI;
        X << xx;
        Y << cos(xx) * exp(-xx / 10.0);
        E << 0.2 * Y.last();
    }
    size_t columnX = ds->addCopiedColumn(X, "x");
    size_t columnY = ds->addCopiedColumn(Y, "y");

    JKQTPImpulsesVerticalGraph* graph = new JKQTPImpulsesVerticalGraph(plot);
    graph->setKeyColumn(columnX);
    graph->setValueColumn(columnY);
    graph->setLineWidth(2);
    graph->setBaseline(0.0);
    graph->setColor(QColor("red"));
    graph->setTitle(QObject::tr("$\\cos(x)\\cdot\\exp(-x/10)$"));

    plot->addGraph(graph);
    plot->getXAxis()->setAxisLabel(QObject::tr("x-axis"));
    plot->getYAxis()->setAxisLabel(QObject::tr("y-axis"));
    plot->getXAxis()->setDrawGrid(false);
    plot->getYAxis()->setDrawGrid(false);
    plot->zoomToFit();
    plot->getPlotter()->setShowKey(false);
    plot->getPlotter()->setPlotLabel(QObject::tr("Impulse Plot"));
}


// 12. Logarithmic axes — resonance curve (logaxes)
void setup_logaxes(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    auto sqr = [](double x) { return x * x; };

    QVector<double> X;
    QVector<double> D {0.001, 0.1, 1, 10};
    const int Ndata = 500;
    for (int i = 0; i < Ndata; i++)
        X << double(i) / double(Ndata) * 3;
    size_t columnX = ds->addCopiedColumn(X, "x");

    QVector<Qt::PenStyle> pens {Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine, Qt::DashDotDotLine};
    for (int id = 0; id < D.size(); id++) {
        QVector<double> Y;
        for (auto& xx : X)
            Y << 1.0 / sqrt(sqr(1 - sqr(xx)) + sqr(2*xx*D[id]));

        JKQTPXYLineGraph* graph = new JKQTPXYLineGraph(plot);
        graph->setXColumn(columnX);
        graph->setYColumn(ds->addCopiedColumn(Y, "y" + QString::number(id)));
        graph->setSymbolType(JKQTPNoSymbol);
        graph->setLineStyle(pens[id % pens.size()]);
        graph->setLineWidth(1.5);
        graph->setTitle(QString("$D=\\delta/\\omega_0=%1$").arg(D[id]));
        plot->addGraph(graph);
    }

    plot->addGraph(new JKQTPGeoText(plot, 1.25, 10,
        "$\\frac{A}{A_{stat}}=\\frac{1}{\\sqrt{\\left(1-\\eta^2\\right)^2+\\left(2{\\eta}D\\right)^2}}$",
        15, QColor("black")));

    plot->getYAxis()->setLogAxis(true);
    plot->getYAxis()->setMinorTicks(9);
    plot->getYAxis()->setDrawMinorGrid(true);
    plot->getYAxis()->setTickLabelType(JKQTPCALTexponent);
    plot->getYAxis()->setLabelDigits(0);
    plot->getYAxis()->setTickLabelFontSize(10);
    plot->getYAxis()->setMinorTickLabelFontSize(7);
    plot->getYAxis()->setLabelFontSize(14);
    plot->getXAxis()->setTickLabelFontSize(10);
    plot->getXAxis()->setMinorTickLabelFontSize(7);
    plot->getXAxis()->setLabelFontSize(14);
    plot->getYAxis()->setAxisLabel("Amplitude $A/A_{stat}$");
    plot->getXAxis()->setAxisLabel("relative driving frequency $\\eta=\\omega/\\omega_0$");
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Logarithmic Axes (Resonance)"));
}


// 13. Parametric scatter — varying symbols/colors/sizes (paramscatterplot)
void setup_paramscatterplot(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    QVector<double> X, Y1, Y2, Y3, Y4, P, C, S, RGB, LW;
    const int Ndata = 10;
    for (int i = 0; i < Ndata; i++) {
        const double x = double(i) / double(Ndata) * 2.0 * JKQTPSTATISTICS_PI;
        X  << x;
        Y1 << 1.5 + sin(x);
        Y2 << 3.5 + sin(x);
        Y3 << 5.5 + sin(x);
        Y4 << 7.5 + sin(x);
        P  << (i + 2);
        C  << x;
        S  << 5 * (i + 1);
        LW << (i + 1) * 1.5;
        RGB << double(qRgb(double(i)/double(Ndata)*255, 0, 255 - double(i)/double(Ndata)*255));
    }
    size_t columnX   = ds->addCopiedColumn(X,   "x");
    size_t columnY1  = ds->addCopiedColumn(Y1,  "y1");
    size_t columnY2  = ds->addCopiedColumn(Y2,  "y2");
    size_t columnY3  = ds->addCopiedColumn(Y3,  "y3");
    size_t columnY4  = ds->addCopiedColumn(Y4,  "y4");
    size_t columnP   = ds->addCopiedColumn(P,   "point_style");
    size_t columnC   = ds->addCopiedColumn(C,   "color_value");
    size_t columnS   = ds->addCopiedColumn(S,   "size");
    size_t columnLW  = ds->addCopiedColumn(LW,  "linewidth");
    size_t columnRGB = ds->addCopiedColumn(RGB, "rgb");

    auto mkGraph = [&](size_t colY, const QString& title) {
        auto* g = new JKQTPXYParametrizedScatterGraph(plot);
        g->setXColumn(columnX); g->setYColumn(colY);
        g->setTitle(title);
        return g;
    };

    auto* g1 = mkGraph(columnY1, "1: symbol type");
    g1->setSymbolColumn(columnP); g1->setDrawLine(true); g1->setColor(QColor("blueviolet"));
    plot->addGraph(g1);

    auto* g2 = mkGraph(columnY2, "2: color");
    g2->setColorColumn(columnC); g2->setColorPalette(JKQTPMathImageRYGB);
    g2->setSymbolType(JKQTPFilledRect); g2->setDrawLine(true);
    g2->getColorBarRightAxis()->setAxisLabel("color scale");
    plot->addGraph(g2);

    auto* g3 = mkGraph(columnY3, "3: symbol size");
    g3->setSizeColumn(columnS); g3->setSymbolType(JKQTPFilledCircle); g3->setDrawLine(true);
    plot->addGraph(g3);

    auto* g4 = mkGraph(columnY4, "4: RGB-color");
    g4->setColorColumn(columnRGB); g4->setColorColumnContainsRGB(true);
    g4->setDrawLine(true); g4->setSymbolType(JKQTPFilledDownTriangle);
    plot->addGraph(g4);

    plot->getPlotter()->setKeyPosition(JKQTPKeyOutsideBottomLeft);
    plot->getMainKey()->setLayout(JKQTPKeyLayoutOneRow);
    plot->getXAxis()->setAxisLabel("x-axis");
    plot->getYAxis()->setAxisLabel("y-axis");
    plot->getXAxis()->setDrawGrid(false);
    plot->getYAxis()->setDrawGrid(false);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Parametric Scatter"));
}


// 14. Parametric curve — logarithmic spiral (parametriccurve)
void setup_parametriccurve(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    QVector<double> X, Y, R;
    const int Ndata = 500;
    const double phiMax = 4.0 * JKQTPSTATISTICS_PI;
    const double a = 1, k = 0.2;
    for (double phi = -phiMax; phi <= phiMax; phi += phiMax / double(Ndata)) {
        const double x = a * exp(k*phi) * cos(phi);
        const double y = a * exp(k*phi) * sin(phi);
        X << x; Y << y; R << sqrt(x*x + y*y);
    }
    size_t columnX = ds->addCopiedColumn(X, "x");
    size_t columnY = ds->addCopiedColumn(Y, "y");
    size_t columnR = ds->addCopiedColumn(R, "r");

    JKQTPXYParametrizedScatterGraph* graph2 = new JKQTPXYParametrizedScatterGraph(plot);
    graph2->setXColumn(columnX);
    graph2->setYColumn(columnY);
    graph2->setColorColumn(columnR);
    graph2->setColorPalette(JKQTPMathImageMATLAB);
    graph2->setSymbolType(JKQTPNoSymbol);
    graph2->setDrawLine(true);
    graph2->setTitle("colored spiral");
    graph2->getColorBarRightAxis()->setAxisLabel("color scale radius $r(\\phi)$");
    plot->addGraph(graph2);

    plot->getPlotter()->setMaintainAspectRatio(true);
    plot->getPlotter()->setAspectRatio(1);
    plot->getXAxis()->setAxisLabel("x-axis");
    plot->getYAxis()->setAxisLabel("y-axis");
    plot->getXAxis()->setDrawGrid(false);
    plot->getYAxis()->setDrawGrid(false);
    plot->setXY(-15, 15, -15, 15);
    plot->getPlotter()->setPlotLabel(QObject::tr("Logarithmic Spiral"));
}


// 15. Secondary Y-axes (second_axis)
void setup_second_axis(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    size_t columnX  = ds->addLinearColumn(40, 0, 10, "x");
    size_t columnY1 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return x; },        "y1");
    size_t columnY2 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return cos(x); },   "y2");
    size_t columnY3 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return x*x; },      "y3");
    size_t columnY4 = ds->addCalculatedColumnFromColumn(columnX, [](double x) { return sqrt(x); },  "y4");

    auto yAxisRef2 = plot->getPlotter()->addSecondaryYAxis(new JKQTPVerticalAxis(plot->getPlotter(), JKQTPPrimaryAxis));
    plot->getYAxis(yAxisRef2)->setDrawGrid(false);
    plot->getYAxis(yAxisRef2)->setDrawMode1(JKQTPCADMnone);
    plot->getYAxis(yAxisRef2)->setDrawMode2(JKQTPCADMcomplete);
    plot->getYAxis(yAxisRef2)->setDrawMode0(JKQTPCADMnone);
    plot->getYAxis(yAxisRef2)->setShowZeroAxis(false);

    auto yAxisRef3 = plot->getPlotter()->addSecondaryYAxis(new JKQTPVerticalAxis(plot->getPlotter(), JKQTPPrimaryAxis));
    plot->getYAxis(yAxisRef3)->setDrawGrid(false);
    plot->getYAxis(yAxisRef3)->setDrawMode1(JKQTPCADMnone);
    plot->getYAxis(yAxisRef3)->setDrawMode2(JKQTPCADMcomplete);
    plot->getYAxis(yAxisRef3)->setDrawMode0(JKQTPCADMnone);
    plot->getYAxis(yAxisRef3)->setShowZeroAxis(false);

    auto yAxisRef4 = plot->getPlotter()->addSecondaryYAxis(new JKQTPVerticalAxis(plot->getPlotter(), JKQTPPrimaryAxis));
    plot->getYAxis(yAxisRef4)->setDrawGrid(false);
    plot->getYAxis(yAxisRef4)->setDrawMode1(JKQTPCADMcomplete);
    plot->getYAxis(yAxisRef4)->setDrawMode2(JKQTPCADMnone);
    plot->getYAxis(yAxisRef4)->setDrawMode0(JKQTPCADMnone);
    plot->getYAxis(yAxisRef4)->setShowZeroAxis(false);

    plot->getYAxis()->setDrawMode2(JKQTPCADMnone);
    plot->getYAxis()->setAxisLabel("graph1");

    JKQTPXYLineGraph* graph1 = new JKQTPXYLineGraph(plot);
    graph1->setKeyColumn(columnX); graph1->setValueColumn(columnY1);
    plot->addGraph(graph1);
    plot->getYAxis()->setColor(graph1->getLineColor());

    JKQTPXYLineGraph* graph2 = new JKQTPXYLineGraph(plot);
    graph2->setKeyColumn(columnX); graph2->setValueColumn(columnY2);
    plot->addGraph(graph2);
    graph2->setYAxis(yAxisRef2);
    plot->getYAxis(yAxisRef2)->setColor(graph2->getLineColor());
    plot->getYAxis(yAxisRef2)->setAxisLabel("graph2");

    JKQTPXYLineGraph* graph3 = new JKQTPXYLineGraph(plot);
    graph3->setKeyColumn(columnX); graph3->setValueColumn(columnY3);
    plot->addGraph(graph3);
    graph3->setYAxis(yAxisRef3);
    plot->getYAxis(yAxisRef3)->setColor(graph3->getLineColor());
    plot->getYAxis(yAxisRef3)->setAxisLabel("graph3");

    JKQTPXYLineGraph* graph4 = new JKQTPXYLineGraph(plot);
    graph4->setKeyColumn(columnX); graph4->setValueColumn(columnY4);
    plot->addGraph(graph4);
    graph4->setYAxis(yAxisRef4);
    plot->getYAxis(yAxisRef4)->setColor(graph4->getLineColor());
    plot->getYAxis(yAxisRef4)->setAxisLabel("graph4");

    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Secondary Axes"));
}


// 16. Stacked bar chart — German energy mix (stackedbars)
void setup_stackedbars(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    QVector<double> year, pct_other, pct_coaloil, pct_gas, pct_nuclear, pct_green;
    year        << 1990  << 1995  << 2000  << 2005  << 2010  << 2015;
    pct_other   << 3.5   << 3.5   << 4.4   << 4.4   << 5.0   << 5.0 ;
    pct_coaloil << 58.7  << 55.7  << 51.5  << 48.2  << 42.9  << 43.1;
    pct_gas     << 6.5   << 7.7   << 8.5   << 11.7  << 14.1  << 9.6 ;
    pct_nuclear << 27.7  << 28.7  << 29.4  << 26.2  << 22.2  << 14.2;
    pct_green   << 3.6   << 4.4   << 6.2   << 9.5   << 15.8  << 28.1;

    size_t cYear    = ds->addCopiedColumn(year,        "year");
    size_t cOther   = ds->addCopiedColumn(pct_other,   "other");
    size_t cCoalOil = ds->addCopiedColumn(pct_coaloil, "coal & oil");
    size_t cGas     = ds->addCopiedColumn(pct_gas,     "natural gas");
    size_t cNuclear = ds->addCopiedColumn(pct_nuclear, "nuclear energy");
    size_t cGreen   = ds->addCopiedColumn(pct_green,   "green energy");

    QVector<JKQTPBarVerticalStackableGraph*> graphs;
    auto addBar = [&](size_t colY, const QString& title, const QString& color) {
        auto* g = new JKQTPBarVerticalStackableGraph(plot);
        g->setXColumn(cYear); g->setYColumn(colY);
        g->setTitle(title);
        g->setFillColor_and_darkenedColor(QColor(color));
        graphs.push_back(g);
        if (graphs.size() > 1)
            g->stackUpon(graphs[graphs.size()-2]);
        plot->addGraph(g);
    };

    addBar(cOther,   QObject::tr("other sources"),  "red");
    addBar(cCoalOil, QObject::tr("coal & oil"),     "darkgrey");
    addBar(cGas,     QObject::tr("natural gas"),    "blue");
    addBar(cNuclear, QObject::tr("nuclear energy"), "gold");
    addBar(cGreen,   QObject::tr("green energy"),   "darkgreen");

    plot->getXAxis()->setAxisLabel("year");
    plot->getYAxis()->setAxisLabel("fraction of energy production in Germany [%]");
    plot->getPlotter()->setKeyPosition(JKQTPKeyOutsideTopRight);
    plot->getMainKey()->setLayout(JKQTPKeyLayoutOneRow);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Stacked Bar Chart"));
}


// 17. Symbols and error bars — sine with errors (symbols_and_errors)
void setup_symbols_and_errors(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    const int Ndata = 10;
    double X[Ndata], Y[Ndata], YERROR[Ndata];
    for (int i = 0; i < Ndata; i++) {
        X[i]      = double(i) / double(Ndata) * 2.0 * JKQTPSTATISTICS_PI;
        Y[i]      = sin(X[i]);
        YERROR[i] = 0.2 + double(i) / double(Ndata) * 0.25;
    }
    size_t columnX  = ds->addCopiedColumn(X,      Ndata, "x");
    size_t columnY  = ds->addCopiedColumn(Y,      Ndata, "y");
    size_t columnYE = ds->addCopiedColumn(YERROR, Ndata, "y-error");

    JKQTPXYLineErrorGraph* graph1 = new JKQTPXYLineErrorGraph(plot);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setYErrorColumn(columnYE);
    graph1->setSymbolType(JKQTPFilledStar);
    graph1->setYErrorStyle(JKQTPErrorBars);
    graph1->setDrawLine(false);
    graph1->setTitle(QObject::tr("sine graph"));
    plot->addGraph(graph1);

    plot->getXAxis()->setShowZeroAxis(false);
    plot->getYAxis()->setShowZeroAxis(false);
    plot->getXAxis()->setAxisLabel(QObject::tr("x-axis $x$ [mm]"));
    plot->getYAxis()->setAxisLabel(QObject::tr("\\textbf{\\color{red}{y-axis} $\\left(y=\\sin(x)\\pm(0.2+0.25\\cdot x)\\right)$ [A.U.]}"));
    plot->getYAxis()->setLabelFontSize(12);
    plot->getYAxis()->setTickLabelFontSize(10);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Symbols and Errors"));
}


// 18. Vector field (vectorfield)
void setup_vectorfield(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* ds = plot->getDatastore();

    const int NX = 9, NY = 9;
    const auto columnXY = ds->addLinearGridColumns(NX, 0, 6, NY, -3, 3, "x", "y");
    const auto columnDX = ds->addCalculatedColumnFromColumn(columnXY.first, columnXY.second,
        [](double x, double y) { return sin(y) * sqrt(x / 3.0); });
    const auto columnDY = ds->addCalculatedColumnFromColumn(columnXY.first, columnXY.second,
        [](double x, double y) { return cos(x) * sqrt(x / 3.0); });

    JKQTPVectorFieldGraph* graph1 = new JKQTPVectorFieldGraph(plot);
    graph1->setXYColumns(columnXY);
    graph1->setDxColumn(columnDX);
    graph1->setDyColumn(columnDY);
    graph1->setTitle(QObject::tr("$\\vec{f}(x,y)=\\bigl[\\sin(y)\\cdot\\sqrt{x/3}, \\cos(x)\\cdot\\sqrt{x/3}\\bigr]^\\mathrm{T}$"));
    plot->addGraph(graph1);

    plot->getPlotter()->setAxisAspectRatio(1);
    plot->getPlotter()->setAspectRatio(1);
    plot->getPlotter()->setMaintainAxisAspectRatio(true);
    plot->getPlotter()->setMaintainAspectRatio(true);
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Vector Field"));
}


// 19. Violin plot — bimodal distribution (violinplot)
void setup_violinplot(JKQTPlotter* plot)
{
    plot->getPlotter()->setUseAntiAliasingForGraphs(true);
    plot->getPlotter()->setUseAntiAliasingForSystem(true);
    plot->getPlotter()->setUseAntiAliasingForText(true);
    JKQTPDatastore* datastore1 = plot->getDatastore();

    size_t randomdatacol1 = datastore1->addColumn("random data N(1,1)+N(6,2)");
    size_t randomdatacol2 = datastore1->addColumn("random data N(1,1)");
    size_t randomdatacol3 = datastore1->addColumn("random data N(6,2)");

    std::mt19937 gen{1236};
    std::normal_distribution<> d1{1, 1};
    std::normal_distribution<> d2{6, 2};
    for (size_t i = 0; i < 40; i++) {
        double v = (i % 2 == 0) ? d1(gen) : d2(gen);
        if (i % 2 == 0)
            datastore1->appendToColumn(randomdatacol2, v);
        else
            datastore1->appendToColumn(randomdatacol3, v);
        datastore1->appendToColumn(randomdatacol1, v);
    }

    auto addRugPlot = [&](size_t col, double position) {
        auto* g = new JKQTPSingleColumnSymbolsGraph(plot);
        g->setPosition(position);
        g->setWidth(0.5);
        g->setPositionScatterStyle(JKQTPSingleColumnSymbolsGraph::RugPlot);
        g->setDataColumn(col);
        g->setDataDirection(JKQTPSingleColumnSymbolsGraph::DataDirection::X);
        plot->addGraph(g);
        return g;
    };

    auto* gData1 = addRugPlot(randomdatacol1, 0.0);
    auto* gData2 = addRugPlot(randomdatacol2, 7.5);
    auto* gData3 = addRugPlot(randomdatacol3, 15.0);

    auto addViolin = [&](size_t col, double pos, JKQTPGraphViolinplotStyleMixin::ViolinStyle vstyle, QColor color) {
        size_t cCat  = datastore1->addColumn("cat");
        size_t cFreq = datastore1->addColumn("freq");
        jkqtpstatKDE1DAutoranged(datastore1->begin(col), datastore1->end(col),
            datastore1->backInserter(cCat), datastore1->backInserter(cFreq),
            51, jkqtpstatKernel1DEpanechnikov,
            jkqtpstatEstimateKDEBandwidth(datastore1->begin(col), datastore1->end(col)));

        auto* gV = new JKQTPViolinplotHorizontalElement(plot);
        gV->setPos(pos);
        gV->setMin(jkqtpstatMinimum(datastore1->begin(col), datastore1->end(col)));
        gV->setMax(jkqtpstatMaximum(datastore1->begin(col), datastore1->end(col)));
        gV->setMean(jkqtpstatAverage(datastore1->begin(col), datastore1->end(col)));
        gV->setMedian(jkqtpstatMedian(datastore1->begin(col), datastore1->end(col)));
        gV->setViolinPositionColumn(cCat);
        gV->setViolinFrequencyColumn(cFreq);
        gV->setColor(color);
        gV->setViolinStyle(vstyle);
        gV->setViolinPositionMode(JKQTPGraphViolinplotStyleMixin::ViolinBoth);
        plot->addGraph(gV);
    };

    addViolin(randomdatacol1, 7.5/2,   JKQTPGraphViolinplotStyleMixin::SmoothViolin, gData1->getSymbolColor());
    addViolin(randomdatacol2, 7.5*1.5, JKQTPGraphViolinplotStyleMixin::StepViolin,   gData2->getSymbolColor());
    addViolin(randomdatacol3, 7.5*2.5, JKQTPGraphViolinplotStyleMixin::BoxViolin,    gData3->getSymbolColor());

    plot->zoomToFit();
    plot->getPlotter()->setKeyPosition(JKQTPKeyInsideBottomRight);
    plot->setShowZeroAxes(false);
    plot->getPlotter()->setGridColor(QColor(230, 230, 230));
    plot->getPlotter()->setPlotLabel(QObject::tr("Violin Plot"));
}


// 20. Wiggle plot — random walk (wiggleplots)
void setup_wiggleplots(JKQTPlotter* plot)
{
    JKQTPDatastore* ds = plot->getDatastore();
    const size_t NSteps = 400;
    const size_t columnT = ds->addLinearColumn(NSteps, 0, NSteps - 1, "time");
    const size_t columnX = ds->addColumn(NSteps, "position");

    double pos = 5;
    const double stepsize = 1;
    std::mt19937 gen{12351};
    std::uniform_int_distribution<int> dist(0, 1);
    for (size_t t = 0; t < NSteps; t++) {
        ds->set(columnX, t, pos);
        pos = pos + stepsize * (static_cast<double>(dist(gen)) * 2.0 - 1.0);
    }

    JKQTPFilledCurveXGraph* graph = new JKQTPFilledCurveXGraph(plot);
    graph->setTitle("Random Walk");
    graph->setXColumn(columnT);
    graph->setYColumn(columnX);
    graph->setFillMode(JKQTPFilledCurveXGraph::TwoColorFilling);
    graph->setLineColor(QColor("black"));
    graph->setLineWidth(1);
    graph->setFillColor(QColor("red"));
    graph->fillStyleBelow().setFillColor(QColor("blue"));
    graph->setBaseline(5);

    plot->addGraph(graph);
    plot->getXAxis()->setAxisLabel("time $t$");
    plot->getYAxis()->setAxisLabel("walker position $x(t)$");
    plot->zoomToFit();
    plot->getPlotter()->setPlotLabel(QObject::tr("Wiggle Plot (Random Walk)"));
}


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("JKQtPlotter Examples");

    QTabWidget* tabs = new QTabWidget(&window);
    window.setCentralWidget(tabs);

    struct Tab { const char* label; void (*setup)(JKQTPlotter*); };
    Tab tabDefs[] = {
        { "Simple Test",         setup_simpletest       },
        { "Scatter",             setup_scatter          },
        { "Bar Chart",           setup_barchart         },
        { "Box Plot",            setup_boxplot          },
        { "Contour Plot",        setup_contourplot      },
        { "Error Bar Styles",    setup_errorbarstyles   },
        { "Eval Curve",          setup_evalcurve        },
        { "Filled Graphs",       setup_filledgraphs     },
        { "Graph Labels",        setup_graphlabels      },
        { "Image Plot",          setup_imageplot        },
        { "Impulse Plot",        setup_impulsesplot     },
        { "Log Axes",            setup_logaxes          },
        { "Param Scatter",       setup_paramscatterplot },
        { "Parametric Curve",    setup_parametriccurve  },
        { "Secondary Axes",      setup_second_axis      },
        { "Stacked Bars",        setup_stackedbars      },
        { "Symbols & Errors",    setup_symbols_and_errors},
        { "Vector Field",        setup_vectorfield      },
        { "Violin Plot",         setup_violinplot       },
        { "Wiggle Plot",         setup_wiggleplots      },
    };

    for (auto& td : tabDefs) {
        auto* plot = new JKQTPlotter(tabs);
        td.setup(plot);
        tabs->addTab(plot, td.label);
    }

    window.resize(900, 700);
    window.show();
    return app.exec();
}
