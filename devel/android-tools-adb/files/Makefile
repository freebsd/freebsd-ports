# $FreeBSD$

PROG_CXX=adb
NOMAN= # DragonFly, NetBSD, OpenBSD
MAN= # FreeBSD
BINDIR?=/usr/bin
FILESDIR?=${DOCDIR}/${PROG}

FILES= OVERVIEW.TXT SERVICES.TXT SYNC.TXT protocol.txt

SRCS+= adb.cpp
SRCS+= adb_io.cpp
SRCS+= adb_listeners.cpp
SRCS+= adb_trace.cpp
SRCS+= adb_utils.cpp
SRCS+= services.cpp
SRCS+= shell_service_protocol.cpp
SRCS+= socket_spec.cpp
SRCS+= ../adb/sockets.cpp
SRCS+= sysdeps_unix.cpp
SRCS+= transport.cpp
SRCS+= transport_local.cpp
SRCS+= transport_usb.cpp

TEST_SRCS+= adb_io_test.cpp
TEST_SRCS+= adb_listeners_test.cpp
TEST_SRCS+= adb_utils_test.cpp
TEST_SRCS+= bugreport_test.cpp
TEST_SRCS+= shell_service_protocol_test.cpp
TEST_SRCS+= socket_spec_test.cpp
TEST_SRCS+= socket_test.cpp
TEST_SRCS+= sysdeps_test.cpp
TEST_SRCS+= transport_test.cpp
TEST_SRCS+= types_test.cpp

.PATH: ${.CURDIR}/client
SRCS+= adb_client.cpp
SRCS+= adb_install.cpp
SRCS+= auth.cpp
SRCS+= bugreport.cpp
SRCS+= commandline.cpp
SRCS+= console.cpp
SRCS+= file_sync_client.cpp
SRCS+= line_printer.cpp
SRCS+= main.cpp
SRCS+= transport_mdns${MDNSEXT}.cpp
SRCS+= usb_libusb.cpp

.PATH: ${.CURDIR}/fdevent
SRCS+= fdevent.cpp
SRCS+= fdevent_poll.cpp
TEST_SRCS+= fdevent_test.cpp

.PATH: ${.CURDIR}/sysdeps
SRCS+= errno.cpp
TEST_SRCS+= stat_test.cpp

.PATH: ${.CURDIR}/sysdeps/posix
SRCS+= network.cpp

.PATH: ${.CURDIR}/../base
SRCS+= chrono_utils.cpp
SRCS+= file.cpp
SRCS+= logging.cpp
SRCS+= parsenetaddress.cpp
SRCS+= stringprintf.cpp
SRCS+= strings.cpp
TEST_SRCS+= file_test.cpp
TEST_SRCS+= logging_test.cpp
TEST_SRCS+= parsenetaddress_test.cpp
TEST_SRCS+= stringprintf_test.cpp
TEST_SRCS+= strings_test.cpp
TEST_SRCS+= test_main.cpp
TEST_SRCS+= test_utils.cpp

.PATH: ${.CURDIR}/../diagnose_usb
SRCS+= diagnose_usb.cpp

.PATH: ${.CURDIR}/../libcrypto_utils
SRCS+= android_pubkey.c

.PATH: ${.CURDIR}/../libcrypto_utils/tests
TEST_SRCS+= android_pubkey_test.cpp

.PATH: ${.CURDIR}/../libcutils
SRCS+= socket_inaddr_any_server_unix.cpp
SRCS+= socket_local_client_unix.cpp
SRCS+= socket_local_server_unix.cpp
SRCS+= socket_network_client_unix.cpp
SRCS+= ../libcutils/sockets.cpp
SRCS+= threads.cpp
# DragonFly, NetBSD, OpenBSD
CPPFLAGS.sockets.cpp+= -o ${.TARGET}

CPPFLAGS+= -DPLATFORM_TOOLS_VERSION="\"${VERSION:U0.0.0}\""
CPPFLAGS+= -DADB_HOST=1
CPPFLAGS+= -Doff64_t=off_t
CPPFLAGS+= -Dlseek64=lseek
CPPFLAGS+= -Dpread64=pread
CPPFLAGS+= -Dpwrite64=pwrite
CPPFLAGS+= -I${.CURDIR}
CPPFLAGS+= -I${.CURDIR}/client
CPPFLAGS+= -I${.CURDIR}/../include
CPPFLAGS+= -I${.CURDIR}/../base/include
CPPFLAGS+= -I${.CURDIR}/../diagnose_usb/include
CPPFLAGS+= -I${.CURDIR}/../libcrypto_utils/include
CPPFLAGS+= ${CPPFLAGS.${.IMPSRC:T}}
CPPFLAGS+= $$(${PKG_CONFIG} libcrypto --cflags 2>/dev/null)
CPPFLAGS+= $$(${PKG_CONFIG} libusb-1.0 --cflags 2>/dev/null)
CXXFLAGS+= -std=gnu++2a

.ifndef COMPILE.c
CFLAGS+= ${CPPFLAGS}
CXXFLAGS+= ${CPPFLAGS}
.endif

TEST_CPPFLAGS+= $$(${PKG_CONFIG} gtest --cflags)
TEST_CPPFLAGS+= $$(${PKG_CONFIG} gmock --cflags)
.for f in ${TEST_SRCS}
CPPFLAGS.${f}+= ${TEST_CPPFLAGS}
.endfor

LDADD+= $$(${PKG_CONFIG} libcrypto --libs 2>/dev/null || echo -lcrypto)
LDADD+= $$(${PKG_CONFIG} libusb-1.0 --libs 2>/dev/null || echo -lusb)
LDADD+= \-lpthread
DPADD+= ${LIBCRYPTO} ${LIBPTHREAD} ${LIBUSB}
TEST_LDADD+= $$(${PKG_CONFIG} gtest --libs)
TEST_LDADD+= $$(${PKG_CONFIG} gmock --libs)

TEST_OBJS+= ${TEST_SRCS:R:S/$/.o/}
CLEANFILES+= ${PROG}_test ${TEST_OBJS}

PKG_CONFIG?= pkg-config

beforeinstall:
	${INSTALL} -d ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>

test: ${PROG}_test
	@for f in ${.ALLSRC}; do ./$$f; done

${PROG}_test: ${OBJS:Nmain.o:Nadb_install.o:Ncommandline.o} ${TEST_OBJS}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}
