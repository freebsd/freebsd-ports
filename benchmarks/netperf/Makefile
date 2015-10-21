# Created by: koshy
# $FreeBSD$

PORTNAME=	netperf
PORTVERSION=	2.7.0
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/ \
		http://fossies.org/unix/misc/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Network performance benchmarking package

OPTIONS_DEFINE=		EXAMPLES EXS HISTOGRAM OMNI SCTP SOCKETS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

EXS_DESC=	Enable ICSC async socket support
HISTOGRAM_DESC=	Enable optional histogram output
OMNI_DESC=	Enable OMNI tests
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix="" --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

INFO=		netperf

HISTOGRAM_CONFIGURE_ENABLE=	histogram
EXS_CONFIGURE_ENABLE=		exs
OMNI_CONFIGURE_ENABLE=		omni
SOCKETS_CONFIGURE_ENABLE=	unixdomain
SCTP_CONFIGURE_ENABLE=		sctp

SCRIPTS=	arr_script bloat.sh packet_byte_script runemomni.sh \
		runemomniagg2.sh runemomniaggdemo.sh sctp_stream_script \
		snapshot_script tcp_range_script tcp_rr_script \
		tcp_stream_script udp_rr_script udp_stream_script

post-patch:
.for i in ${SCRIPTS}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/doc/examples/$i
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/examples/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
