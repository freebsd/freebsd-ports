# $FreeBSD$

PORTNAME=	libosmo-sccp
PORTVERSION=	0.0.6.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/ \
		http://ns1.chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	SCCP network layer protocol implementation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:${PORTSDIR}/devel/libosmocore

CONFLICTS_INSTALL=libmtp-[0-9]* # lib/libmtp.a

USES=		autoreconf gmake pathfix pkgconfig
PATHFIX_MAKEFILEIN=Makefile.am
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,endian\.h,sys/endian.h,' \
		-e 's,__BYTE_ORDER,BYTE_ORDER,' \
		-e 's,__LITTLE_ENDIAN,LITTLE_ENDIAN,' \
		-e 's,__BIG_ENDIAN,BIG_ENDIAN,' \
		${WRKSRC}/include/mtp/mtp_level3.h \
		${WRKSRC}/include/sccp/sccp_types.h
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
