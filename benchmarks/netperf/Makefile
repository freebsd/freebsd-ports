# Created by: koshy
# $FreeBSD$

PORTNAME=	netperf
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/ \
		http://fossies.org/unix/misc/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Network performance benchmarking package

OPTIONS_DEFINE=		OMNI SCTP SOCKETS HISTOGRAM EXS
OPTIONS_DEFAULT=	SCTP SOCKETS HISTOGRAM EXS

OMNI_DESC=	Enable OMNI tests
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support
HISTOGRAM_DESC=	Enable optional histogram output
EXS_DESC=	Enable ICSC async socket support

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix=""  --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

.include <bsd.port.options.mk>

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

SCRIPTS=	arr_script packet_byte_script sctp_stream_script snapshot_script \
		tcp_range_script tcp_rr_script tcp_stream_script udp_rr_script \
		udp_stream_script

post-patch:
.for i in ${SCRIPTS}
	@${REINPLACE_CMD} -e 's^%%PREFIX%%^${PREFIX}^' ${WRKSRC}/doc/examples/$i
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/examples/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
