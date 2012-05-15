# New ports collection makefile for: netperf
# Date created:		19 July 1996
# Whom:			koshy
#
# $FreeBSD$
#

PORTNAME=	netperf
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/ \
		http://fossies.org/unix/misc/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Network performance benchmarking package

OPTIONS=	SOCKETS		"Enable Unix Domain socket support" On \
		SCTP		"Enable SCTP support" On \
		EXS		"Enable ICSC async socket support" On \
		HISTOGRAM	"Enable optional histogram output" On \
		OMNI		"Enable OMNI tests" Off \

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix=""  --program-suffix="" --enable-dirty \
		--enable-demo --enable-burst --enable-intervals

.if !defined(WITHOUT_SOCKETS)
CONFIGURE_ARGS+=	--enable-unixdomain
.else
CONFIGURE_ARGS+=	--disable-unixdomain
.endif

.if !defined(WITHOUT_SCTP)
CONFIGURE_ARGS+=	--enable-sctp
.else
CONFIGURE_ARGS+=	--disable-sctp
.endif

.if !defined(WITHOUT_EXS)
CONFIGURE_ARGS+=	--enable-exs
.else
CONFIGURE_ARGS+=	--disable-exs
.endif

.if !defined(WITHOUT_HISTOGRAM)
CONFIGURE_ARGS+=	--enable-histogram
.else
CONFIGURE_ARGS+=	--disable-histogram
.endif

.if !defined(WITHOUT_OMNI)
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
