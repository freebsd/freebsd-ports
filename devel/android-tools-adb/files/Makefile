# $FreeBSD$

PROG=	adb
NO_MAN=
BINDIR?=/usr/bin

SRCS+= adb.c
SRCS+= adb_client.c
SRCS+= adb_auth_host.c
SRCS+= commandline.c
SRCS+= console.c
SRCS+= file_sync_client.c
SRCS+= fdevent.c
SRCS+= get_my_path_freebsd.c
SRCS+= services.c
SRCS+= sockets.c
SRCS+= transport.c
SRCS+= transport_local.c
SRCS+= transport_usb.c
SRCS+= usb_libusb.c
SRCS+= usb_vendors.c

.PATH: ${.CURDIR}/../libcutils
SRCS+= socket_inaddr_any_server.c
SRCS+= socket_local_client.c
SRCS+= socket_local_server.c
SRCS+= socket_loopback_client.c
SRCS+= socket_loopback_server.c
SRCS+= socket_network_client.c
SRCS+= load_file.c

.PATH: ${.CURDIR}/../libzipfile
SRCS+= centraldir.c
SRCS+= zipfile.c

CPPFLAGS+= -DADB_HOST=1
CPPFLAGS+= -DHAVE_FORKEXEC=1
CPPFLAGS+= -DHAVE_SYMLINKS
CPPFLAGS+= -DHAVE_TERMIO_H
CPPFLAGS+= -DHAVE_SYS_SOCKET_H
CPPFLAGS+= -D_FILE_OFFSET_BITS=64
CPPFLAGS+= -I${.CURDIR}
CPPFLAGS+= -I${.CURDIR}/../include

.ifndef COMPILE.c
CFLAGS+= ${CPPFLAGS}
.endif

LDADD+= -lcrypto -lpthread -lusb -lz
DPADD+= ${LIBCRYPTO} ${LIBPTHREAD} ${LIBUSB} ${LIBZ}

.include <bsd.prog.mk>
