# Created by: koshy
# $FreeBSD$

PORTNAME=	netperf
PORTVERSION=	2.6.0
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/ \
		http://fossies.org/unix/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network performance benchmarking package

OPTIONS_DEFINE=		OMNI SCTP SOCKETS HISTOGRAM EXS
OPTIONS_DEFAULT=	SCTP SOCKETS HISTOGRAM EXS

OMNI_DESC=	Enable OMNI tests
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support
HISTOGRAM_DESC=	Enable optional histogram output
EXS_DESC=	Enable ICSC async socket support

.include <bsd.port.options.mk>

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix=""  --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

.if ${PORT_OPTIONS:MSOCKETS}
CONFIGURE_ARGS+=	--enable-unixdomain
.else
CONFIGURE_ARGS+=	--disable-unixdomain
.endif

.if ${PORT_OPTIONS:MSCTP}
CONFIGURE_ARGS+=	--enable-sctp
.else
CONFIGURE_ARGS+=	--disable-sctp
.endif

.if ${PORT_OPTIONS:MEXS}
CONFIGURE_ARGS+=	--enable-exs
.else
CONFIGURE_ARGS+=	--disable-exs
.endif

.if ${PORT_OPTIONS:MHISTOGRAM}
CONFIGURE_ARGS+=	--enable-histogram
.else
CONFIGURE_ARGS+=	--disable-histogram
.endif

.if ${PORT_OPTIONS:MOMNI}
CONFIGURE_ARGS+=	--enable-omni
.else
CONFIGURE_ARGS+=	--disable-omni
.endif

MAN1=		netperf.1 netserver.1
INFO=		netperf
SCRIPTS=	arr_script packet_byte_script sctp_stream_script snapshot_script \
		tcp_range_script tcp_rr_script tcp_stream_script udp_rr_script \
		udp_stream_script

post-patch:
.for i in ${SCRIPTS}
	@${REINPLACE_CMD} -e 's^%%PREFIX%%^${PREFIX}^' ${WRKSRC}/doc/examples/$i
.endfor

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/examples/$i ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
