# Created by: jesper@jdn.dk
# $FreeBSD$

PORTNAME=	sipp
PORTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	SIP benchmarking and testing tool

LICENSE=	GPLv2

PLIST_FILES=	bin/sipp man/man1/sipp.1.gz

USES=		autoreconf gmake ncurses
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	OPENSSL GSL PCAP RTPSTREAM SCTP
OPTIONS_DEFAULT=	OPENSSL PCAP RTPSTREAM
OPENSSL_DESC=	OpenSSL support (for digest auth and SIP over TLS)
GSL_DESC=	GSL support (for statistical distributed pauses)
PCAP_DESC=	PCAP Support
RTPSTREAM_DESC=	RTP Streaming Support
SCTP_DESC=	SCTP Transport Protocol Support

GSL_CONFIGURE_WITH=	gsl
SCTP_CONFIGURE_WITH=	sctp
RTPSTREAM_CONFIGURE_WITH=	rtpstream
OPENSSL_CONFIGURE_WITH=	openssl

OPENSSL_USES=		ssl
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

PCAP_FILES=	dtmf_2833_0.pcap dtmf_2833_1.pcap dtmf_2833_2.pcap \
		dtmf_2833_3.pcap dtmf_2833_4.pcap dtmf_2833_5.pcap \
		dtmf_2833_6.pcap dtmf_2833_7.pcap dtmf_2833_8.pcap \
		dtmf_2833_9.pcap dtmf_2833_pound.pcap dtmf_2833_star.pcap \
		g711a.pcap

PCAP_PLIST_FILES=	${PCAP_FILES:S|^|${DATADIR}/pcap/|}

post-patch:
	@${REINPLACE_CMD} -e 's|[[:<:]]curses|ncurses|' ${WRKSRC}/configure.ac

post-patch-PCAP-on:
	@${REINPLACE_CMD} \
		's|\(\\"\)\(pcap/[^"]*\.pcap\\"\)|\1${DATADIR}/\2|' \
		${WRKSRC}/src/scenario.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/include/sipp.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-PCAP-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/pcap
.for f in ${PCAP_FILES}
	${INSTALL_DATA} ${WRKSRC}/pcap/${f} ${STAGEDIR}${DATADIR}/pcap/${f}
.endfor

.include <bsd.port.mk>
