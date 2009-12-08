# New ports collection makefile for:    sipp
# Date created:         15 Jun 2004
# Whom:                 jesper@jdn.dk
#
# $FreeBSD$
#

PORTNAME=	sipp
PORTVERSION=	3.1.20090729
CATEGORIES=	benchmarks net
MASTER_SITES=	http://sipp.sourceforge.net/snapshots/
DISTNAME=	${PORTNAME}.2009-07-29

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	SIP testing tool

PLIST_FILES=	bin/sipp
MAN1=		sipp.1

USE_GMAKE=	yes
MAKE_ENV+=	CPP="${CXX}" \
		CPPFLAGS="${CXXFLAGS}" \
		CCLINK="${CXX}"
WRKSRC=		${WRKDIR}/sipp.svn

OPTIONS=	OPENSSL		"OpenSSL support (for digest auth and SIP over TLS)" on \
		GSL		"GSL support (for statistical distributed pauses)" off \
		PCAPPLAY	"RTP play support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GSL)
LIB_DEPENDS+=	gsl.14:${PORTSDIR}/math/gsl

MAKE_ENV+=	EXTRACPPFLAGS=-DHAVE_GSL \
		EXTRACFLAGS=-DHAVE_GSL \
		EXTRALIBS='-lgsl -lgslcblas'
.endif #defined(WITH_GSL)

.if defined(WITH_PCAPPLAY)
PCAP_FILES=	dtmf_2833_1.pcap dtmf_2833_2.pcap dtmf_2833_3.pcap \
		dtmf_2833_4.pcap dtmf_2833_5.pcap dtmf_2833_6.pcap \
		dtmf_2833_7.pcap dtmf_2833_8.pcap dtmf_2833_9.pcap \
		dtmf_2833_pound.pcap dtmf_2833_star.pcap g711a.pcap

PLIST_DIRS=	%%DATADIR%%/pcap \
		%%DATADIR%%

.for f in ${PCAP_FILES}
PLIST_FILES+=	%%DATADIR%%/pcap/${f}
.endfor
.endif #defined(WITH_PCAPPLAY)

.if defined(WITHOUT_OPENSSL)

.if defined(WITH_PCAPPLAY)
ALL_TARGET=	pcapplay
.endif #defined(WITH_PCAPPLAY)

.else #!defined(WITHOUT_OPENSSL)

.if defined(WITH_PCAPPLAY)
ALL_TARGET=	pcapplay_ossl
.else
ALL_TARGET=	ossl
.endif #defined(WITH_PCAPPLAY)

.endif #defined(WITHOUT_OPENSSL)

post-patch:
.if ${ARCH} == "ia64"
	@${REINPLACE_CMD} 's/^\(MFLAGS_ia64=\)\+DD64$$/\1/' ${WRKSRC}/Makefile
.endif

.if defined(WITH_PCAPPLAY)
	@${REINPLACE_CMD} \
		's|\(\\"\)\(pcap/[^"]*\.pcap\\"\)|\1${DATADIR}/\2|' \
		${WRKSRC}/scenario.cpp
.endif #defined(WITH_PCAPPLAY)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/sipp.1 ${PREFIX}/man/man1

.if defined(WITH_PCAPPLAY)
	${MKDIR} ${DATADIR}/pcap

.for f in ${PCAP_FILES}
	${INSTALL_DATA} ${WRKSRC}/pcap/${f} ${DATADIR}/pcap/${f}
.endfor

.endif #defined(WITH_PCAPPLAY)

.include <bsd.port.post.mk>
