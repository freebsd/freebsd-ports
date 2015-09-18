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
TEST_SRCS+= transport_test.cpp
CFLAGS.shell_service_protocol_test.cpp+= -Dsighandler_t=sig_t

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
CFLAGS.logd_write.c+= -DFAKE_LOG_DEVICE=1

CFLAGS+= -DADB_HOST=1
CFLAGS+= -DHAVE_FORKEXEC=1
CFLAGS+= -DHAVE_SYMLINKS
CFLAGS+= -DHAVE_TERMIO_H
CFLAGS+= -DHAVE_SYS_SOCKET_H
CFLAGS+= -D_FILE_OFFSET_BITS=64
CFLAGS+= -I${.CURDIR}
CFLAGS+= -I${.CURDIR}/../include
CFLAGS+= -I${.CURDIR}/../base/include
CFLAGS+=${CFLAGS.${.IMPSRC:T}}

CXXFLAGS+= -std=gnu++11
CXXFLAGS+= ${CFLAGS:N-std*}

TEST_CFLAGS+= $$(${GTEST_CONFIG} --cppflags)
.for f in ${TEST_SRCS}
CFLAGS.${f}+= ${TEST_CFLAGS}
.endfor

LDADD+= -lcrypto -lpthread -lusb -lz
DPADD+= ${LIBCRYPTO} ${LIBPTHREAD} ${LIBUSB} ${LIBZ}
TEST_LDADD+= $$(${GTEST_CONFIG} --libs --ldflags)

GTEST_CONFIG?= gtest-config

adb_test: ${SRCS:R:S/$/.o/:Nmain.o:Ncommandline.o} ${TEST_SRCS:R:S/$/.o/}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}

.include <bsd.prog.mk>
