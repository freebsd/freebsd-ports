# $FreeBSD$

SRCS=		malloc.c malloc.h
STATIC_LIB=	libdlmalloc.a
STATIC_LIB_R=	libdlmalloc_r.a
SHARED_OBJ=	dlmalloc_module.so
SHARED_OBJ_R=	dlmalloc_module_r.so
THR_SAFE_FLAG=	-DUSE_MALLOC_LOCK ${PTHREAD_CFLAGS}
CFLAGS+=	-I${.CURDIR}

all: ${STATIC_LIB} ${STATIC_LIB_R} ${SHARED_OBJ} ${SHARED_OBJ_R}

malloc.o: ${SRCS}
	${CC} -c ${CFLAGS} -o ${.TARGET} malloc.c

malloc_r.o: ${SRCS}
	${CC} -c ${CFLAGS} ${THR_SAFE_FLAG} -o ${.TARGET} malloc.c

malloc.so: ${SRCS}
	${CC} -c ${CFLAGS} -fPIC -DPIC -o ${.TARGET} malloc.c

malloc_r.so: ${SRCS}
	${CC} -c ${CFLAGS} ${THR_SAFE_FLAG} -fPIC -DPIC -o ${.TARGET} malloc.c

${STATIC_LIB}: malloc.o
	${AR} cq ${.TARGET} malloc.o

${STATIC_LIB_R}: malloc_r.o
	${AR} cq ${.TARGET} malloc_r.o

${SHARED_OBJ}: malloc.so
	${CC} -shared -o ${.TARGET} malloc.so

${SHARED_OBJ_R}: malloc_r.so
	${CC} -shared -o ${.TARGET} malloc_r.so ${PTHREAD_LIBS}
