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
CPPFLAGS.init.c+=	-DDARWIN # statfs

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
CPPFLAGS.centraldir.c+=	-Ulseek64 # utils/Compat.h

CPPFLAGS+=	-D_FILE_OFFSET_BITS=64 # utils/Compat.h
CPPFLAGS+=	-Doff64_t=off_t
CPPFLAGS+=	-Dftruncate64=ftruncate
CPPFLAGS+=	-Dlseek64=lseek
CPPFLAGS+=	-Dmmap64=mmap
CPPFLAGS+=	-I${.CURDIR}
CPPFLAGS+=	-I${.CURDIR}/../include
CPPFLAGS+=	-I${.CURDIR}/../mkbootimg
CPPFLAGS+=	-I${.CURDIR}/../ext4_utils
CPPFLAGS+=	-I${.CURDIR}/../f2fs_utils
CPPFLAGS+=	-I${.CURDIR}/../libselinux/include
CPPFLAGS+=	-I${.CURDIR}/../libsparse/include
CPPFLAGS+=	${CPPFLAGS.${.IMPSRC:T}}

.ifndef COMPILE.c
CFLAGS+=	${CPPFLAGS}
.endif

LDADD+=	-lpcre -lusb -lz
DPADD+=	${LIBPCRE} ${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
