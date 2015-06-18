# $FreeBSD$

PROG_CXX=fastboot
BINDIR?=/usr/bin

SRCS+=	bootimg_utils.cpp
SRCS+=	engine.c
SRCS+=	fastboot.cpp
SRCS+=	fs.c
SRCS+=	protocol.c
SRCS+=	util.c

.PATH:	${FILESDIR}
SRCS+=	usb_freebsd.c
SRCS+=	util_freebsd.c

# required by libziparchive
.PATH: ${.CURDIR}/../base
SRCS+=	file.cpp

# required by fastboot
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
SRCS+=	wipe.c

# required by base and libutils
.PATH:	${.CURDIR}/../liblog
SRCS+=	fake_log_device.c
SRCS+=	logd_write.c
CFLAGS.logd_write.c+=	-DFAKE_LOG_DEVICE=1

# required by ext4_utils
.PATH:	${.CURDIR}/../libselinux/src
SRCS+=	callbacks.c
SRCS+=	check_context.c
SRCS+=	freecon.c
SRCS+=	init.c
SRCS+=	label.c
SRCS+=	label_android_property.c
SRCS+=	label_file.c
CFLAGS.init.c+=		-DDARWIN # statfs

# required by fastboot and ext4_utils
.PATH:	${.CURDIR}/../libsparse
SRCS+=	backed_block.c
SRCS+=	output_file.c
SRCS+=	sparse.c
SRCS+=	sparse_crc32.c
SRCS+=	sparse_err.c
SRCS+=	sparse_read.c

# required by libziparchive
.PATH: ${.CURDIR}/../libutils
SRCS+=	FileMap.cpp

# required by fastboot
.PATH:	${.CURDIR}/../libziparchive
SRCS+=	zip_archive.cc

CFLAGS+=-Doff64_t=off_t
CFLAGS+=-Dftruncate64=ftruncate
CFLAGS+=-Dlseek64=lseek
CFLAGS+=-Dmmap64=mmap
CFLAGS+=-Dpread64=pread
CFLAGS+=-I${.CURDIR}
CFLAGS+=-I${.CURDIR}/../include
CFLAGS+=-I${.CURDIR}/../mkbootimg
CFLAGS+=-I${.CURDIR}/../base/include
CFLAGS+=-I${.CURDIR}/../ext4_utils
CFLAGS+=-I${.CURDIR}/../f2fs_utils
CFLAGS+=-I${.CURDIR}/../libselinux/include
CFLAGS+=-I${.CURDIR}/../libsparse/include
CFLAGS+=${CFLAGS.${.IMPSRC:T}}

CXXFLAGS+=-D__STDC_LIMIT_MACROS # DragonFly
CXXFLAGS+=-std=gnu++11
CXXFLAGS+=${CFLAGS:N-std*}

LDADD+=	-lpcre -lusb -lz
DPADD+=	${LIBPCRE} ${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
