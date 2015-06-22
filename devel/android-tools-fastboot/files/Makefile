# $FreeBSD$

PROG=	fastboot
BINDIR?=/usr/bin

SRCS+=	bootimg.c
SRCS+=	engine.c
SRCS+=	fastboot.c
SRCS+=	fs.c
SRCS+=	protocol.c
SRCS+=	util.c

.PATH:	${FILESDIR}
SRCS+=	usb_freebsd.c
SRCS+=	util_freebsd.c

.PATH: ${.CURDIR}/../ext4_utils
SRCS+=	allocate.c
SRCS+=	contents.c
SRCS+=	crc16.c
SRCS+=	ext4_sb.c
SRCS+=	ext4_utils.c
SRCS+=	ext4fixup.c
SRCS+=	extent.c
SRCS+=	indirect.c
SRCS+=	make_ext4fs.c
SRCS+=	sha1.c
SRCS+=	uuid.c
SRCS+=	wipe.c

.PATH:	${.CURDIR}/../libselinux/src
SRCS+=	callbacks.c
SRCS+=	check_context.c
SRCS+=	freecon.c
SRCS+=	init.c
SRCS+=	label.c
SRCS+=	label_android_property.c
SRCS+=	label_file.c
CFLAGS.init.c+=		-DDARWIN # statfs

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
CFLAGS.centraldir.c+=	-Ulseek64 # utils/Compat.h

CFLAGS+=-D_FILE_OFFSET_BITS=64 # utils/Compat.h
CFLAGS+=-Doff64_t=off_t
CFLAGS+=-Dftruncate64=ftruncate
CFLAGS+=-Dlseek64=lseek
CFLAGS+=-Dmmap64=mmap
CFLAGS+=-I${.CURDIR}
CFLAGS+=-I${.CURDIR}/../include
CFLAGS+=-I${.CURDIR}/../mkbootimg
CFLAGS+=-I${.CURDIR}/../ext4_utils
CFLAGS+=-I${.CURDIR}/../f2fs_utils
CFLAGS+=-I${.CURDIR}/../libselinux/include
CFLAGS+=-I${.CURDIR}/../libsparse/include
CFLAGS+=${CFLAGS.${.IMPSRC:T}}

LDADD+=	-lpcre -lusb -lz
DPADD+=	${LIBPCRE} ${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
