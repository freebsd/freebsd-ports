# New ports collection makefile for:    sipp
# Date created:         15 Jun 2004
# Whom:                 jesper@jdn.dk
#
# $FreeBSD$
#

PORTNAME=	sipp
PORTVERSION=	1.1.r6.20061208
CATEGORIES=	net
MASTER_SITES=	http://sipp.sourceforge.net/snapshots/
DISTNAME=	${PORTNAME}.2006-12-08

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	SIP testing tool

PLIST_FILES=	bin/sipp
MAN1=		sipp.1

MAKE_ENV+=	CPP="${CXX}" CPPFLAGS="${CXXFLAGS}" CCLINK="${CXX}"

.include <bsd.port.pre.mk>

.if defined(WITH_PCAPPLAY)
BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

PCAP_FILES=	dtmf_2833_1.pcap dtmf_2833_2.pcap dtmf_2833_3.pcap \
		dtmf_2833_4.pcap dtmf_2833_5.pcap dtmf_2833_6.pcap \
		dtmf_2833_7.pcap dtmf_2833_8.pcap dtmf_2833_9.pcap \
		dtmf_2833_pound.pcap dtmf_2833_star.pcap g711a.pcap

PLIST_DIRS=	%%DATADIR%%/pcap %%DATADIR%%

.for f in ${PCAP_FILES}
PLIST_FILES+=	%%DATADIR%%/pcap/${f}
.endfor
.endif

.if defined(WITHOUT_DIGEST_AUTH)

.if defined(WITH_PCAPPLAY)
ALL_TARGET=	pcapplay
.endif #defined(WITH_PCAPPLAY)

.else

.if defined(WITH_PCAPPLAY)
ALL_TARGET=	pcapplay_ossl
.else
ALL_TARGET=	ossl
.endif #defined(WITH_PCAPPLAY)

.endif #defined(WITHOUT_DIGEST_AUTH)

post-patch:
.if ${ARCH} == "ia64"
	@${REINPLACE_CMD} 's/^\(MFLAGS_ia64=\)\+DD64$$/\1/' ${WRKSRC}/Makefile
.endif

.if defined(WITH_PCAPPLAY)
	@${REINPLACE_CMD} \
		's|\(\\"\)\(pcap/[^"]*\.pcap\\"\)|\1${DATADIR}/\2|' \
		${WRKSRC}/scenario.cpp
.endif

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
