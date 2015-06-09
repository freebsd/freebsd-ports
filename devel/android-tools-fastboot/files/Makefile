# $FreeBSD$

PROG=	fastboot
NO_MAN=
BINDIR?=/usr/bin

SRCS+=	bootimg.c
SRCS+=	engine.c
SRCS+=	fastboot.c
SRCS+=	protocol.c

.PATH:	${FILESDIR}
SRCS+=	usb_freebsd.c
SRCS+=	util_freebsd.c

.PATH:	${.CURDIR}/../libzipfile
SRCS+=	centraldir.c
SRCS+=	zipfile.c

CFLAGS+=-I.
CFLAGS+=-I../include
CFLAGS+=-I../mkbootimg

LDADD+=	-lusb -lz
DPADD+=	${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
