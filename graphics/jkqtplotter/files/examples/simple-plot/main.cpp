/*
 * Simple JKQTPlotter example: sine wave plot.
 *
 * Build with CMake:
 *   mkdir build && cd build
 *   cmake .. -DJKQTPlotter6_DIR=/usr/local/lib/cmake/JKQTPlotter6
 *   make
 */
#include <QApplication>
#include <cmath>
#include "jkqtplotter/jkqtplotter.h"
#include "jkqtplotter/graphs/jkqtpscatter.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    JKQTPlotter plot;
    JKQTPDatastore* ds = plot.getDatastore();

    /* Fill data store with a sine wave. */
    const int N = 200;
    size_t colX = ds->addColumn(N, "x");
    size_t colY = ds->addColumn(N, "y");
    for (int i = 0; i < N; i++) {
        double x = i * 2.0 * M_PI / (N - 1);
        ds->set(colX, i, x);
        ds->set(colY, i, std::sin(x));
    }

    auto* graph = new JKQTPXYLineGraph(&plot);
    graph->setXColumn(colX);
    graph->setYColumn(colY);
    graph->setTitle("sin(x)");
    plot.addGraph(graph);

    plot.setWindowTitle("JKQTPlotter Simple Example");
    plot.setXAxisLabel("x");
    plot.setYAxisLabel("y");
    plot.zoomAllX();
    plot.show();

    return app.exec();
}
