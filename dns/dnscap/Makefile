# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnscap
PORTVERSION=	1.11.0
PORTEPOCH=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dnscap/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNS network traffic capture utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool localbase pkgconfig ssl

CONFIGURE_ARGS=	--enable-shared --enable-static
CONFIGURE_ENV=	libcrypto_CFLAGS=-I${OPENSSLINC}/include \
		libcrypto_LIBS="-L${OPENSSLLIB}/lib -lcrypto"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CDS DOCS THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_SUB=	yes
CDS_DESC=	CBOR DNS Stream (CDS) format (experimental)

CDS_CONFIGURE_OFF=	ac_cv_lib_ldns_ldns_wire2pkt=no \
			ac_cv_lib_tinycbor_cbor_parser_init=no
CDS_LIB_DEPENDS=	libldns.so:dns/ldns \
			libtinycbor.so:devel/tinycbor
THREADS_CONFIGURE_ENABLE=	threads

post-patch:
	@${REINPLACE_CMD} -e 's|\(HAVE_\)\(CBOR_CBOR_H\)|\1TINY\2|; s|cbor/cbor.h|tiny&|' ${WRKSRC}/configure.ac ${WRKSRC}/src/dump_cbor.c ${WRKSRC}/src/dump_cds.c

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^install-data-am: / s| install-dist_docDATA||' ${WRKSRC}/Makefile.am

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^dist_doc_DATA = / s| LICENSE||' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
