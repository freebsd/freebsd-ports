PORTNAME=	libsmpp34
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an implementation of SMPP-3.4 protocol for PDUs handling
WWW=		https://c-open-smpp-34.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gnome libtool pathfix
USE_GNOME=	libxml2

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
