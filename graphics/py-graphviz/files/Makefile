# $FreeBSD$

all: _graphviz.so

_graphviz.so: gv_wrap.o
	${CC} -shared ${LOCALBASE}/lib/graphviz/libagraph.so ${LOCALBASE}/lib/graphviz/libcdt.so gv_wrap.o -o _graphviz.so

gv_wrap.o: gv_wrap.c
	${CC} -fno-strict-aliasing -DNDEBUG -O -pipe -DTHREAD_STACK_SIZE=0x20000 -fPIC -Dulong=u_long -DVERSION="py-agraph 1.0" -I${GRAPHVIZ_INCLUDEDIR} -I${PYTHON_INCLUDEDIR} ${CFLAGS} -c gv_wrap.c

gv_wrap.c:
	${SWIG_CMD} -python gv.i 
