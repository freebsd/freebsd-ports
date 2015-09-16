# Created by: koshy
# $FreeBSD$

PORTNAME=	netperf
PORTVERSION=	2.6.0
PORTREVISION=	3
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/ \
		http://fossies.org/unix/misc/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Network performance benchmarking package

OPTIONS_DEFINE=		OMNI SCTP SOCKETS HISTOGRAM EXS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

OMNI_DESC=	Enable OMNI tests
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support
HISTOGRAM_DESC=	Enable optional histogram output
EXS_DESC=	Enable ICSC async socket support

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix="" --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

INFO=		netperf

SOCKETS_CONFIGURE_ENABLE=	unixdomain
SCTP_CONFIGURE_ENABLE=		sctp
EXS_CONFIGURE_ENABLE=		exs
HISTOGRAM_CONFIGURE_ENABLE=	histogram
OMNI_CONFIGURE_ENABLE=		omni

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
