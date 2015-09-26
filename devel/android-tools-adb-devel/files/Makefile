# $FreeBSD$

PROG_CXX=adb
NO_MAN=
BINDIR?=/usr/bin

SRCS+= adb.cpp
SRCS+= adb_auth.cpp
SRCS+= adb_auth_host.cpp
SRCS+= adb_client.cpp
SRCS+= adb_io.cpp
SRCS+= adb_listeners.cpp
SRCS+= adb_utils.cpp
SRCS+= commandline.cpp
SRCS+= console.cpp
SRCS+= fdevent.cpp
SRCS+= file_sync_client.cpp
SRCS+= services.cpp
SRCS+= shell_service_protocol.cpp
SRCS+= sockets.cpp
SRCS+= transport.cpp
SRCS+= transport_local.cpp
SRCS+= transport_usb.cpp

TEST_SRCS+= adb_io_test.cpp
TEST_SRCS+= adb_utils_test.cpp
TEST_SRCS+= fdevent_test.cpp
TEST_SRCS+= shell_service_protocol_test.cpp
TEST_SRCS+= socket_test.cpp
TEST_SRCS+= transport_test.cpp

.PATH: ${.CURDIR}/client
SRCS+= main.cpp

.PATH: ${FILESDIR}
SRCS+= get_my_path_freebsd.cpp
SRCS+= usb_libusb.cpp

.PATH: ${.CURDIR}/../base
SRCS+= file.cpp
SRCS+= logging.cpp
SRCS+= strings.cpp
SRCS+= stringprintf.cpp
TEST_SRCS+= file_test.cpp
TEST_SRCS+= logging_test.cpp
TEST_SRCS+= stringprintf_test.cpp
TEST_SRCS+= strings_test.cpp
TEST_SRCS+= test_main.cpp
TEST_SRCS+= test_utils.cpp

.PATH: ${.CURDIR}/../libcutils
SRCS+= socket_inaddr_any_server.c
SRCS+= socket_local_client.c
SRCS+= socket_local_server.c
SRCS+= socket_loopback_client.c
SRCS+= socket_loopback_server.c
SRCS+= socket_network_client.c
SRCS+= load_file.c
SRCS+= threads.c

# required by base/file.cpp
.PATH: ${.CURDIR}/../liblog
SRCS+= fake_log_device.c
SRCS+= logd_write.c
CPPFLAGS.logd_write.c+= -DFAKE_LOG_DEVICE=1

CPPFLAGS+= -DADB_HOST=1
CPPFLAGS+= -DHAVE_FORKEXEC=1
CPPFLAGS+= -DHAVE_SYMLINKS
CPPFLAGS+= -DHAVE_TERMIO_H
CPPFLAGS+= -DHAVE_SYS_SOCKET_H
CPPFLAGS+= -D_FILE_OFFSET_BITS=64
CPPFLAGS+= -I${.CURDIR}
CPPFLAGS+= -I${.CURDIR}/../include
CPPFLAGS+= -I${.CURDIR}/../base/include
CPPFLAGS+= ${CPPFLAGS.${.IMPSRC:T}}
CXXFLAGS+= -std=gnu++11

.ifndef COMPILE.c
CFLAGS+= ${CPPFLAGS}
CXXFLAGS+= ${CPPFLAGS}
.endif

TEST_CPPFLAGS+= $$(${GTEST_CONFIG} --cppflags)
.for f in ${TEST_SRCS}
CPPFLAGS.${f}+= ${TEST_CPPFLAGS}
.endfor

LDADD+= -lcrypto -lpthread -lusb -lz
DPADD+= ${LIBCRYPTO} ${LIBPTHREAD} ${LIBUSB} ${LIBZ}
TEST_LDADD+= $$(${GTEST_CONFIG} --libs --ldflags)

GTEST_CONFIG?= gtest-config

adb_test: ${SRCS:R:S/$/.o/:Nmain.o:Ncommandline.o} ${TEST_SRCS:R:S/$/.o/}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}

.include <bsd.prog.mk>
