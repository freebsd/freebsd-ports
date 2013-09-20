# $FreeBSD$

PORTNAME=	libmodbus
PORTVERSION=	3.1.0
CATEGORIES=	comms

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Modbus library

LICENSE=	LGPL21

USE_GITHUB=	yes
GH_ACCOUNT=	stephane
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix

PLIST_FILES=	include/modbus/modbus-rtu.h include/modbus/modbus-tcp.h \
		include/modbus/modbus-version.h include/modbus/modbus.h \
		lib/libmodbus.la lib/libmodbus.so lib/libmodbus.so.6 \
		libdata/pkgconfig/libmodbus.pc
PLIST_DIRS=	include/modbus
MAN3=		modbus_close.3 modbus_connect.3 modbus_flush.3 modbus_free.3 \
		modbus_get_byte_from_bits.3 modbus_get_byte_timeout.3 \
		modbus_get_float.3 modbus_get_header_length.3 \
		modbus_get_response_timeout.3 modbus_get_socket.3 \
		modbus_mapping_free.3 modbus_mapping_new.3 modbus_new_rtu.3 \
		modbus_new_tcp.3 modbus_new_tcp_pi.3 modbus_read_bits.3 \
		modbus_read_input_bits.3 modbus_read_input_registers.3 \
		modbus_read_registers.3 modbus_receive.3 \
		modbus_receive_confirmation.3 modbus_receive_from.3 \
		modbus_reply.3 modbus_reply_exception.3 \
		modbus_report_slave_id.3 modbus_rtu_get_rts.3 \
		modbus_rtu_get_serial_mode.3 modbus_rtu_set_rts.3 \
		modbus_rtu_set_serial_mode.3 modbus_send_raw_request.3 \
		modbus_set_bits_from_byte.3 modbus_set_bits_from_bytes.3 \
		modbus_set_byte_timeout.3 modbus_set_debug.3 \
		modbus_set_error_recovery.3 modbus_set_float.3 \
		modbus_set_response_timeout.3 modbus_set_slave.3 \
		modbus_set_socket.3 modbus_strerror.3 modbus_tcp_listen.3 \
		modbus_write_and_read_registers.3 modbus_write_bit.3 \
		modbus_write_bits.3 modbus_write_register.3 \
		modbus_write_registers.3
MAN7=		libmodbus.7

NO_STAGE=	yes
.include <bsd.port.mk>
