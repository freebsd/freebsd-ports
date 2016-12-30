# $FreeBSD$
SRCS=	web-mode.el
OBJS=	${SRCS:C/.el$/.elc/}

.SUFFIXES:
.SUFFIXES: .el .elc
.el.elc:
	${EMACS} -batch -q -f batch-byte-compile ${.IMPSRC}

all: ${OBJS}

install: ${OBJS}
	mkdir -p ${DESTDIR}${LISPDIR}
	${BSD_INSTALL_DATA} ${.ALLSRC} ${DESTDIR}${LISPDIR}
	cd ${DESTDIR}${LISPDIR} && gzip -9 ${.ALLSRC}
