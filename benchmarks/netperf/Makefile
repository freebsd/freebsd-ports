# New ports collection makefile for: netperf
# Date created:		19 July 1996
# Whom:			koshy
#
# $FreeBSD$
#

PORTNAME=	netperf
PORTVERSION=	2.4.5
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.netperf.org/netperf/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Network performance benchmarking package

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"transform="
CONFIGURE_ARGS=	--program-prefix=""  --program-suffix=""
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
