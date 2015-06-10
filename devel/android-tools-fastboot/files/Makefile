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

.PATH: ${.CURDIR}/../ext4_utils
SRCS+=	allocate.c
SRCS+=	contents.c
SRCS+=	ext4_utils.c
SRCS+=	ext4fixup.c
SRCS+=	extent.c
SRCS+=	indirect.c
SRCS+=	make_ext4fs.c
SRCS+=	sha1.c
SRCS+=	uuid.c
SRCS+=	wipe.c

.PATH:	${.CURDIR}/../libsparse
SRCS+=	backed_block.c
SRCS+=	output_file.c
SRCS+=	sparse.c
SRCS+=	sparse_crc32.c
SRCS+=	sparse_err.c
SRCS+=	sparse_read.c

.PATH:	${.CURDIR}/../libzipfile
SRCS+=	centraldir.c
SRCS+=	zipfile.c

CFLAGS+=-D__APPLE__ -D__MACH__ # off64_t
CFLAGS+=-I${.CURDIR}
CFLAGS+=-I${.CURDIR}/../include
CFLAGS+=-I${.CURDIR}/../mkbootimg
CFLAGS+=-I${.CURDIR}/../ext4_utils
CFLAGS+=-I${.CURDIR}/../libsparse/include

LDADD+=	-lusb -lz
DPADD+=	${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
