CC=		%%CC%%
RM=		%%RM%%
CFLAGS=		%%CFLAGS%% -I. -I%%X11BASE%%/include -I%%PREFIX%%/include/
LDFLAGS=	-L%%X11BASE%%/lib -L%%PREFIX%%/lib -lagl -lGL -lGLU

ALLEGRO_CFLAGS!=%%ALLEGRO_CONFIG%% --cflags
ALLEGRO_LFLAGS!=%%ALLEGRO_CONFIG%% --libs
CFLAGS+=	${ALLEGRO_CFLAGS}
LDFLAGS+=	${ALLEGRO_LFLAGS}

TARGETS= dialog dumbtest exalleg exalpfnt excamera exext exgui exmasked \
		extext extextur test tex

all: ${TARGETS}

dialog: dialog.o
	${CC} $> -o $@ ${LDFLAGS}	

dumbtest: dumbtest.o
	${CC} $> -o $@ ${LDFLAGS}

exalleg: exalleg.o
	${CC} $> -o $@ ${LDFLAGS}

exalpfnt: exalpfnt.o
	${CC} $> -o $@ ${LDFLAGS}

excamera: excamera.o
	${CC} $> -o $@ ${LDFLAGS}

exext: exext.o
	${CC} $> -o $@ ${LDFLAGS}

exgui: exgui.o
	${CC} $> -o $@ ${LDFLAGS}

exmasked: exmasked.o
	${CC} $> -o $@ ${LDFLAGS}

extext: extext.o
	${CC} $> -o $@ ${LDFLAGS}

extextur: extextur.o
	${CC} $> -o $@ ${LDFLAGS}

test: test.o
	${CC} $> -o $@ ${LDFLAGS}

tex: tex.o
	${CC} $> -o $@ ${LDFLAGS}


.c.o:
	${CC} -c ${CFLAGS} $*.c

clean:
	${RM} -f *.o ${TARGETS}
