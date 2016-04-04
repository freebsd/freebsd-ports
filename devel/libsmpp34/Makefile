# $FreeBSD$

PORTNAME=	libsmpp34
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/ \
		http://ns1.chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Provide an implementation of SMPP-3.4 protocol for PDUs handling

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf libtool gmake

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e 's|AC_CONFIG_AUX_DIR.*|AC_CONFIG_AUX_DIR([.])|g' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|AM_CONFIG_HEADER.*|AM_CONFIG_HEADER([./config.h])|g' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_dumpBuf.c
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_dumpPdu.c
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_pack.c
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_params.c
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_structs.c
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/smpp34_unpack.c
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
