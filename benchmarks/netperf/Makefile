# Created by: koshy
# $FreeBSD$

PORTNAME=	netperf
PORTVERSION=	2.7.1.p20170921
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Network performance benchmarking package

USE_GITHUB=	yes
GH_ACCOUNT=	HewlettPackard
#GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_TAGNAME=	d566775bf

OPTIONS_DEFINE=		EXAMPLES EXS HISTOGRAM INFO OMNI SCTP SOCKETS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

EXS_DESC=	Enable ICSC async socket support
HISTOGRAM_DESC=	Enable histogram output
OMNI_DESC=	Enable OMNI tests (disable for aio(4) support)
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix="" --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

INFO_INFO=	netperf

EXS_CONFIGURE_ENABLE=		exs
HISTOGRAM_CONFIGURE_ENABLE=	histogram
OMNI_CONFIGURE_ENABLE=		omni
SCTP_CONFIGURE_ENABLE=		sctp
SOCKETS_CONFIGURE_ENABLE=	unixdomain

SCRIPTS=	arr_script bloat.sh find_max_burst.sh packet_byte_script \
		remote_hosts runemomni.sh runemomniagg2.sh runemomniaggdemo.sh \
		sctp_stream_script snapshot_script tcp_range_script \
		tcp_rr_script tcp_stream_script udp_rr_script \
		udp_stream_script

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
