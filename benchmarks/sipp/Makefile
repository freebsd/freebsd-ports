# Created by: jesper@jdn.dk
# $FreeBSD$

PORTNAME=	sipp
PORTVERSION=	3.3
CATEGORIES=	benchmarks net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sipp/sipp/${PORTVERSION}
DISTNAME=	${PORTNAME}-3.3beta2

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	SIP benchmarking and testing tool

LICENSE=	GPLv2

PLIST_FILES=	bin/sipp
MAN1=		sipp.1

USE_GMAKE=	yes
CPP=		${CXX}
MAKE_ENV+=	CCLINK="${CXX}"
CPPFLAGS+=	${CXXFLAGS}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	OPENSSL GSL PCAPPLAY
OPTIONS_DEFAULT=	OPENSSL
OPENSSL_DESC=	OpenSSL support (for digest auth and SIP over TLS)
GSL_DESC=	GSL support (for statistical distributed pauses)
PCAPPLAY_DESC=	RTP play support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl

MAKE_ENV+=	EXTRACPPFLAGS=-DHAVE_GSL \
		EXTRACFLAGS=-DHAVE_GSL \
		EXTRALIBS='-lgsl -lgslcblas'
.endif #defined(WITH_GSL)

.if ${PORT_OPTIONS:MPCAPPLAY}
PCAP_FILES=	dtmf_2833_0.pcap dtmf_2833_1.pcap dtmf_2833_2.pcap \
		dtmf_2833_3.pcap dtmf_2833_4.pcap dtmf_2833_5.pcap \
		dtmf_2833_6.pcap dtmf_2833_7.pcap dtmf_2833_8.pcap \
		dtmf_2833_9.pcap dtmf_2833_pound.pcap dtmf_2833_star.pcap \
		g711a.pcap

PLIST_DIRS=	%%DATADIR%%/pcap \
		%%DATADIR%%

.for f in ${PCAP_FILES}
PLIST_FILES+=	%%DATADIR%%/pcap/${f}
.endfor
.endif #defined(WITH_PCAPPLAY)

.if ${PORT_OPTIONS:MOPENSSL}

.if ${PORT_OPTIONS:MPCAPPLAY}
ALL_TARGET=	pcapplay_ossl
.else
ALL_TARGET=	ossl
.endif #defined(WITH_PCAPPLAY)

.else # ! ${PORT_OPTIONS:MOPENSSL}

.if ${PORT_OPTIONS:MPCAPPLAY}
ALL_TARGET=	pcapplay
.endif #defined(WITH_PCAPPLAY)


.endif #defined(WITHOUT_OPENSSL)

post-patch:
.if ${ARCH} == "ia64"
	@${REINPLACE_CMD} 's/^\(MFLAGS_ia64=\)\+DD64$$/\1/' ${WRKSRC}/Makefile
.endif

.if ${PORT_OPTIONS:MPCAPPLAY}
	@${REINPLACE_CMD} \
		's|\(\\"\)\(pcap/[^"]*\.pcap\\"\)|\1${DATADIR}/\2|' \
		${WRKSRC}/scenario.cpp
.endif #defined(WITH_PCAPPLAY)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/sipp.1 ${PREFIX}/man/man1

.if ${PORT_OPTIONS:MPCAPPLAY}
	${MKDIR} ${DATADIR}/pcap

.for f in ${PCAP_FILES}
	${INSTALL_DATA} ${WRKSRC}/pcap/${f} ${DATADIR}/pcap/${f}
.endfor

.endif #defined(WITH_PCAPPLAY)

.include <bsd.port.mk>
