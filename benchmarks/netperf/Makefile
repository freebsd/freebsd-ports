PORTNAME=	netperf
PORTVERSION=	2.7.1.p20210121
PORTREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Network performance benchmarking package
WWW=		https://hewlettpackard.github.io/netperf/

USES=		autoreconf:build,2.69

USE_GITHUB=	yes
GH_ACCOUNT=	HewlettPackard
#GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_TAGNAME=	3bc455b23

OPTIONS_DEFINE=		EXAMPLES EXS HISTOGRAM INFO OMNI SCTP SOCKETS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

EXS_DESC=	Enable ICSC async socket support
HISTOGRAM_DESC=	Enable histogram output
OMNI_DESC=	Enable OMNI tests (disable for aio(4) support)
SCTP_DESC=	Enable SCTP support
SOCKETS_DESC=	Enable Unix Domain socket support

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-burst --enable-demo --enable-dirty --enable-intervals
CFLAGS+=	-fcommon

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
	@${REINPLACE_CMD} -E -e 's,(conf|header),\12.69,g' ${WRKSRC}/autogen.sh

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/examples/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
