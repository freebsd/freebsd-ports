# $FreeBSD$

PROG_CXX=fastboot
BINDIR?=/usr/bin
FILESDIR?=${DOCDIR}/${PROG}

FILES=	README.md

SRCS+=	bootimg_utils.cpp
SRCS+=	fastboot.cpp
SRCS+=	fastboot_driver.cpp
SRCS+=	../fastboot/fs.cpp
SRCS+=	main.cpp
SRCS+=	socket.cpp
SRCS+=	tcp.cpp
SRCS+=	udp.cpp
SRCS+=	util.cpp

.PATH: ${EXTRADIR}
SRCS+=	usb_libusb.cpp

# required by fastboot, diagnose_usb and libziparchive
.PATH: ${.CURDIR}/../base
SRCS+=	errors_unix.cpp
SRCS+=	file.cpp
SRCS+=	liblog_symbols.cpp
SRCS+=	logging.cpp
SRCS+=	mapped_file.cpp
SRCS+=	parsenetaddress.cpp
SRCS+=	stringprintf.cpp
SRCS+=	strings.cpp
SRCS+=	threads.cpp

# required by fastboot
.PATH: ${.CURDIR}/../diagnose_usb
SRCS+=	diagnose_usb.cpp

# required by fs_mgr/liblp
.PATH: ${.CURDIR}/../extras/ext4_utils
SRCS+=	ext4_sb.cpp
SRCS+=	ext4_utils.cpp

# required by fastboot
.PATH: ${.CURDIR}/../fs_mgr/liblp
SRCS+=	images.cpp
SRCS+=	partition_opener.cpp
SRCS+=	reader.cpp
SRCS+=	utility.cpp
SRCS+=	writer.cpp

# required by fastboot
.PATH: ${.CURDIR}/../libcutils
SRCS+=	android_get_control_file.cpp
SRCS+=	../libcutils/sockets.cpp
SRCS+=	socket_inaddr_any_server_unix.cpp
SRCS+=	socket_network_client_unix.cpp
SRCS+=	sockets_unix.cpp
# DragonFly, NetBSD, OpenBSD
CPPFLAGS.sockets.cpp+=	-o ${.TARGET}

# required by base and zip_archive
.PATH: ${.CURDIR}/../liblog
SRCS+= logger_write.cpp
SRCS+= ../liblog/properties.cpp

# required by fastboot
.PATH:	${.CURDIR}/../libsparse
SRCS+=	backed_block.cpp
SRCS+=	output_file.cpp
SRCS+=	sparse.cpp
SRCS+=	sparse_crc32.cpp
SRCS+=	sparse_err.cpp
SRCS+=	sparse_read.cpp

# required by fastboot
.PATH:	${.CURDIR}/../libziparchive
SRCS+=	zip_archive.cc

CPPFLAGS+=	-DPLATFORM_TOOLS_VERSION="\"${VERSION:U0.0.0}\""
CPPFLAGS+=	-Doff64_t=off_t
CPPFLAGS+=	-Dftruncate64=ftruncate
CPPFLAGS+=	-Dlseek64=lseek
CPPFLAGS+=	-Dmmap64=mmap
CPPFLAGS+=	-I${.CURDIR}
CPPFLAGS+=	-I${.CURDIR}/../include
CPPFLAGS+=	-I${.CURDIR}/../avb
CPPFLAGS+=	-I${.CURDIR}/../base/include
CPPFLAGS+=	-I${.CURDIR}/../diagnose_usb/include
CPPFLAGS+=	-I${.CURDIR}/../extras/ext4_utils/include
CPPFLAGS+=	-I${.CURDIR}/../fs_mgr/liblp/include
CPPFLAGS+=	-I${.CURDIR}/../libsparse/include
CPPFLAGS+=	-I${.CURDIR}/../libziparchive/include
CPPFLAGS+=	-I${.CURDIR}/../mkbootimg/include/bootimg
CPPFLAGS+=	${CPPFLAGS.${.IMPSRC:T}}
CPPFLAGS+=	$$(${PKG_CONFIG} libcrypto --cflags 2>/dev/null)
CPPFLAGS+=	$$(${PKG_CONFIG} libusb-1.0 --cflags 2>/dev/null)
CXXFLAGS+=	-D__STDC_LIMIT_MACROS # DragonFly
CXXFLAGS+=	-std=gnu++17

.ifndef COMPILE.c
CFLAGS+=	${CPPFLAGS}
CXXFLAGS+=	${CPPFLAGS}
.endif

LDADD+=	$$(${PKG_CONFIG} libcrypto --libs 2>/dev/null || echo -lcrypto)
LDADD+=	$$(${PKG_CONFIG} libusb-1.0 --libs 2>/dev/null || echo -lusb)
LDADD+=	-lz \-lpthread
DPADD+=	${LIBPTHREAD} ${LIBUSB} ${LIBZ}

PKG_CONFIG?=	pkg-config

beforeinstall:
	${INSTALL} -d ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
