# $FreeBSD$

PROG_CXX=fastboot
BINDIR?=/usr/bin
FILESDIR?=${DOCDIR}/${PROG}
VERSION?=0.0.0-0

FILES=	*.md

SRCS+=	bootimg_utils.cpp
SRCS+=	engine.cpp
SRCS+=	fastboot.cpp
SRCS+=	../fastboot/fs.cpp
SRCS+=	protocol.cpp
SRCS+=	socket.cpp
SRCS+=	tcp.cpp
SRCS+=	udp.cpp
SRCS+=	util.cpp

.PATH: ${EXTRADIR}
SRCS+=	usb_freebsd.cpp

# required by fastboot
.PATH: ${.CURDIR}/../adb
SRCS+=	diagnose_usb.cpp

# required by fastboot, diagnose_usb and libziparchive
.PATH: ${.CURDIR}/../base
SRCS+=	errors_unix.cpp
SRCS+=	file.cpp
SRCS+=	logging.cpp
SRCS+=	parsenetaddress.cpp
SRCS+=	stringprintf.cpp
SRCS+=	strings.cpp

# required by fastboot
.PATH: ${.CURDIR}/../libcutils
SRCS+=	android_get_control_file.cpp
SRCS+=	../libcutils/sockets.cpp
SRCS+=	socket_inaddr_any_server_unix.cpp
SRCS+=	socket_network_client_unix.cpp
SRCS+=	sockets_unix.cpp
CPPFLAGS.sockets.cpp+=	-o ${.TARGET} # XXX pre-r279980

# required by base and libutils
.PATH:	${.CURDIR}/../liblog
SRCS+=	config_read.c
SRCS+=	config_write.c
SRCS+=	fake_log_device.c
SRCS+=	fake_writer.c
SRCS+=	local_logger.c
SRCS+=	logger_lock.c
SRCS+=	logger_name.c
SRCS+=	logger_write.c
SRCS+=	logprint.c
SRCS+=	stderr_write.c
SRCS+=	test_utils.cpp

# required by fastboot
.PATH:	${.CURDIR}/../libsparse
SRCS+=	backed_block.c
SRCS+=	output_file.c
SRCS+=	sparse.c
SRCS+=	sparse_crc32.c
SRCS+=	sparse_err.c
SRCS+=	sparse_read.cpp

# required by libziparchive
.PATH: ${.CURDIR}/../libutils
SRCS+=	FileMap.cpp

# required by fastboot
.PATH:	${.CURDIR}/../libziparchive
SRCS+=	zip_archive.cc

CPPFLAGS+=	-DFASTBOOT_VERSION="\"${VERSION}\""
CPPFLAGS+=	-Doff64_t=off_t
CPPFLAGS+=	-Dftruncate64=ftruncate
CPPFLAGS+=	-Dlseek64=lseek
CPPFLAGS+=	-Dmmap64=mmap
CPPFLAGS+=	-Dpread64=pread
CPPFLAGS+=	-DFAKE_LOG_DEVICE=1
CPPFLAGS+=	-I${.CURDIR}
CPPFLAGS+=	-I${.CURDIR}/../include
CPPFLAGS+=	-I${.CURDIR}/../adb
CPPFLAGS+=	-I${.CURDIR}/../mkbootimg/include/bootimg
CPPFLAGS+=	-I${.CURDIR}/../base/include
CPPFLAGS+=	-I${.CURDIR}/../libsparse/include
CPPFLAGS+=	-I${.CURDIR}/../libziparchive/include
CPPFLAGS+=	${CPPFLAGS.${.IMPSRC:T}}
CPPFLAGS+=	$$(${PKG_CONFIG} libusb-1.0 --cflags 2>/dev/null)
CXXFLAGS+=	-D__STDC_LIMIT_MACROS # DragonFly
CXXFLAGS+=	-std=gnu++11

.ifndef COMPILE.c
CFLAGS+=	${CPPFLAGS}
CXXFLAGS+=	${CPPFLAGS}
.endif

LDADD+=	$$(${PKG_CONFIG} libusb-1.0 --libs 2>/dev/null || echo -lusb)
LDADD+=	-lz \-lpthread
DPADD+=	${LIBPTHREAD} ${LIBUSB} ${LIBZ}

PKG_CONFIG?=	pkg-config

beforeinstall:
	${INSTALL} -d ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
