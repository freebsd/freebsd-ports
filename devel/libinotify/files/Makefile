# $FreeBSD$

SHLIB=		inotify
SHLIB_MAJOR=	0

DPADD=		${LIBPTHREAD}
LDADD=		-lpthread

SRCS=		utils.c
SRCS+=		compat.c
SRCS+=		conversions.c
SRCS+=		dep-list.c
SRCS+=		inotify-watch.c
SRCS+=		watch-set.c
SRCS+=		watch.c
SRCS+=		worker-thread.c
SRCS+=		worker.c
SRCS+=		controller.c

INCS=		sys/inotify.h

CFLAGS+=	-I${.CURDIR} -DNDEBUG -pthread

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include/sys

LIBOWN!=	id -un
LIBGRP!=	id -gn
BINOWN=		${LIBOWN}
BINGRP=		${LIBGRP}

beforeinstall:
	@mkdir -p ${DESTDIR}/${LIBDIR} ${DESTDIR}/${INCLUDEDIR}

.include <bsd.lib.mk>
