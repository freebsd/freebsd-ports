# $FreeBSD$

PORTNAME=	libsmpp34
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an implementation of SMPP-3.4 protocol for PDUs handling

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf libtool pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/smpp34_dumpBuf.c \
		${WRKSRC}/src/smpp34_dumpPdu.c \
		${WRKSRC}/src/smpp34_pack.c \
		${WRKSRC}/src/smpp34_params.c \
		${WRKSRC}/src/smpp34_structs.c \
		${WRKSRC}/src/smpp34_unpack.c
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
