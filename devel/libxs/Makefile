# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxs
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.crossroads.io/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Open source lightweight messaging layer

GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GCC=	yes

OPTIONS_DEFINE=	DEBUG DOCS PLUGINS ZMQ
EXTERNAL_DESC=	PGM extension from ports
INTERNAL_DESC=	PGM extension
PLUGINS_DESC=	Additional plugins
ZMQ_DESC=	Compatibility with ZMQ
OPTIONS_RADIO=		PGM
OPTIONS_RADIO_PGM=	INTERNAL EXTERNAL
OPTIONS_DEFAULT=PLUGINS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml

MAN3=	\
	xs_bind.3 \
	xs_close.3 \
	xs_connect.3 \
	xs_errno.3 \
	xs_getmsgopt.3 \
	xs_getsockopt.3 \
	xs_init.3 \
	xs_msg_close.3 \
	xs_msg_copy.3 \
	xs_msg_data.3 \
	xs_msg_init.3 \
	xs_msg_init_data.3 \
	xs_msg_init_size.3 \
	xs_msg_move.3 \
	xs_msg_size.3 \
	xs_poll.3 \
	xs_recv.3 \
	xs_recvmsg.3 \
	xs_send.3 \
	xs_sendmsg.3 \
	xs_setctxopt.3 \
	xs_setsockopt.3 \
	xs_shutdown.3 \
	xs_socket.3 \
	xs_strerror.3 \
	xs_term.3 \
	xs_version.3

MAN7=	\
	xs.7 \
	xs_inproc.7 \
	xs_ipc.7 \
	xs_pgm.7 \
	xs_tcp.7 \
	xs_zmq.7
.else
CONFIGURE_ARGS+=	--without-documentation
.endif

.if ${PORT_OPTIONS:MINTERNAL}
CONFIGURE_ARGS+=	--with-pgm
USES+=			perl5
CFLAGS+=		-fPIC
.endif

.if ${PORT_OPTIONS:MEXTERNAL}
CONFIGURE_ARGS+=	--with-system-pgm
LIB_DEPENDS+=		pgm:${PORTSDIR}/net/openpgm
.endif

.if ${PORT_OPTIONS:MPLUGINS}
CONFIGURE_ARGS+=	--enable-plugins=yes
.else
CONFIGURE_ARGS+=	--enable-plugins=no
.endif

.if ${PORT_OPTIONS:MZMQ}
CONFIGURE_ARGS+=	--enable-libzmq
CONFLICTS=	zmq-*
PLIST_SUB+=	ZMQ=""
.else
PLIST_SUB+=	ZMQ="@comment "
.endif

pre-configure:
# fix for clang build
	@${REINPLACE_CMD} "/^libxs_werror=/ s|yes|no|" \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MEXTERNAL}
	${REINPLACE_CMD} "s|openpgm-5.1|openpgm-5.2|g" \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
