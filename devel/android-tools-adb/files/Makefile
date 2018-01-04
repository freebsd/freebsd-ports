# $FreeBSD$

PROG_CXX=adb
NO_MAN=
BINDIR?=/usr/bin
FILESDIR?=${DOCDIR}/${PROG}
VERSION?= 0.0.0-0

FILES= *.[Tt][Xx][Tt]

SRCS+= adb.cpp
SRCS+= adb_auth_host.cpp
SRCS+= adb_client.cpp
SRCS+= adb_io.cpp
SRCS+= adb_listeners.cpp
SRCS+= adb_trace.cpp
SRCS+= adb_utils.cpp
SRCS+= bugreport.cpp
SRCS+= commandline.cpp
SRCS+= console.cpp
SRCS+= diagnose_usb.cpp
SRCS+= fdevent.cpp
SRCS+= file_sync_client.cpp
SRCS+= line_printer.cpp
SRCS+= services.cpp
SRCS+= shell_service_protocol.cpp
SRCS+= socket_spec.cpp
SRCS+= ../adb/sockets.cpp
SRCS+= sysdeps_unix.cpp
SRCS+= transport.cpp
SRCS+= transport_local.cpp
SRCS+= transport_mdns${MDNSEXT}.cpp
SRCS+= transport_usb.cpp

TEST_SRCS+= adb_io_test.cpp
TEST_SRCS+= adb_listeners_test.cpp
TEST_SRCS+= adb_utils_test.cpp
TEST_SRCS+= bugreport_test.cpp
TEST_SRCS+= fdevent_test.cpp
TEST_SRCS+= shell_service_protocol_test.cpp
TEST_SRCS+= socket_spec_test.cpp
TEST_SRCS+= socket_test.cpp
TEST_SRCS+= sysdeps_test.cpp
TEST_SRCS+= transport_test.cpp

.PATH: ${.CURDIR}/client
SRCS+= main.cpp
SRCS+= usb_libusb.cpp

.PATH: ${.CURDIR}/sysdeps
SRCS+= errno.cpp
TEST_SRCS+= stat_test.cpp

.PATH: ${.CURDIR}/sysdeps/posix
SRCS+= network.cpp

.PATH: ${.CURDIR}/../base
SRCS+= file.cpp
SRCS+= logging.cpp
SRCS+= parsenetaddress.cpp
SRCS+= quick_exit.cpp
SRCS+= stringprintf.cpp
SRCS+= strings.cpp
TEST_SRCS+= file_test.cpp
TEST_SRCS+= logging_test.cpp
TEST_SRCS+= parsenetaddress_test.cpp
TEST_SRCS+= quick_exit_test.cpp
TEST_SRCS+= stringprintf_test.cpp
TEST_SRCS+= strings_test.cpp
TEST_SRCS+= test_main.cpp
TEST_SRCS+= test_utils.cpp

.PATH: ${.CURDIR}/../libcrypto_utils
SRCS+= android_pubkey.c

.PATH: ${.CURDIR}/../libcrypto_utils/tests
TEST_SRCS+= android_pubkey_test.cpp

.PATH: ${.CURDIR}/../libcutils
SRCS+= socket_inaddr_any_server_unix.c
SRCS+= socket_local_client_unix.c
SRCS+= socket_local_server_unix.c
SRCS+= socket_network_client_unix.c
SRCS+= ../libcutils/sockets.cpp
SRCS+= load_file.c
SRCS+= threads.c
# XXX Obsolete after 10.2 or r279980/r280329
CPPFLAGS.sockets.cpp+= -o ${.TARGET}

# required by base/file.cpp
.PATH: ${.CURDIR}/../liblog
SRCS+= config_read.c
SRCS+= config_write.c
SRCS+= fake_log_device.c
SRCS+= fake_writer.c
SRCS+= local_logger.c
SRCS+= logger_lock.c
SRCS+= logger_name.c
SRCS+= logger_write.c
SRCS+= logprint.c
SRCS+= stderr_write.c

CPPFLAGS+= -DADB_VERSION="\"${VERSION}\""
CPPFLAGS+= -DADB_HOST=1
CPPFLAGS+= -DHAVE_FORKEXEC=1
CPPFLAGS+= -DHAVE_SYMLINKS
CPPFLAGS+= -DHAVE_TERMIO_H
CPPFLAGS+= -DHAVE_SYS_SOCKET_H
CPPFLAGS+= -D_FILE_OFFSET_BITS=64
CPPFLAGS+= -DFAKE_LOG_DEVICE=1
CPPFLAGS+= -I${.CURDIR}
CPPFLAGS+= -I${.CURDIR}/../include
CPPFLAGS+= -I${.CURDIR}/../base/include
CPPFLAGS+= -I${.CURDIR}/../libcrypto_utils/include
CPPFLAGS+= ${CPPFLAGS.${.IMPSRC:T}}
CPPFLAGS+= $$(${PKG_CONFIG} libcrypto --cflags 2>/dev/null)
CPPFLAGS+= $$(${PKG_CONFIG} libusb-1.0 --cflags 2>/dev/null)
CXXFLAGS+= -std=gnu++14

.ifndef COMPILE.c
CFLAGS+= ${CPPFLAGS}
CXXFLAGS+= ${CPPFLAGS}
.endif

TEST_CPPFLAGS+= $$(${GTEST_CONFIG} --cppflags)
TEST_CPPFLAGS+= $$(${GMOCK_CONFIG} --cppflags)
.for f in ${TEST_SRCS}
CPPFLAGS.${f}+= ${TEST_CPPFLAGS}
.endfor

LDADD+= $$(${PKG_CONFIG} libcrypto --libs 2>/dev/null || echo -lcrypto)
LDADD+= $$(${PKG_CONFIG} libusb-1.0 --libs 2>/dev/null || echo -lusb)
LDADD+= -lz \-lpthread
DPADD+= ${LIBCRYPTO} ${LIBPTHREAD} ${LIBUSB} ${LIBZ}
TEST_LDADD+= $$(${GTEST_CONFIG} --libs --ldflags)
TEST_LDADD+= $$(${GMOCK_CONFIG} --libs --ldflags)

TEST_OBJS+= ${TEST_SRCS:R:S/$/.o/}
CLEANFILES+= ${PROG}_test ${TEST_OBJS}

GTEST_CONFIG?= gtest-config
GMOCK_CONFIG?= gmock-config
PKG_CONFIG?= pkg-config

beforeinstall:
	${INSTALL} -d ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>

test: ${PROG}_test
	@for f in ${.ALLSRC}; do ./$$f; done

${PROG}_test: ${OBJS:Nmain.o:Ncommandline.o} ${TEST_OBJS}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}
