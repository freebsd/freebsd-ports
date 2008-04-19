# Make sure, that you have graphics/libglut installed
# in order to build example program
#
# $FreeBSD$

CC=		%%CC%%
CXX=		%%CXX%%
RM=		%%RM%%
CFLAGS=		%%CFLAGS%% -I. -I%%LOCALBASE%%/include -I%%PREFIX%%/include/FTGL
CXXFLAGS=	%%CXXFLAGS%% -I. -I%%LOCALBASE%%/include -I%%PREFIX%%/include/FTGL
LDFLAGS=	-L%%LOCALBASE%%/lib -L%%LOCALBASE%%/lib -lglut -lftgl

FREETYPE_CFLAGS!=%%LOCALBASE%%/bin/freetype-config --cflags
FREETYPE_LFLAGS!=%%LOCALBASE%%/bin/freetype-config --libs

CFLAGS+=	${FREETYPE_CFLAGS}
CXXFLAGS+=	${FREETYPE_CFLAGS}
LDFLAGS+=	${FREETYPE_LFLAGS}

FTGLDemo: tb.o trackball.o FTGLDemo.o
	${CXX} $> -o $@ ${LDFLAGS}

.cpp.o:
	${CXX} -c ${CXXFLAGS} $*.cpp

.c.o:
	${CC} -c ${CFLAGS} $*.c

clean:
	${RM} -f FTGLDemo *.o
