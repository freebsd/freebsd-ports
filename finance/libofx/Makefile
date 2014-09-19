# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$

PORTNAME=	libofx
PORTVERSION=	0.9.10
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libosp.so:${PORTSDIR}/textproc/opensp

USES=		gmake iconv pkgconfig pathfix libtool
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS DOXYGEN

.include <bsd.port.options.mk>

post-install:
	${RM} -f ${STAGEDIR}${DOCSDIR}/COPYING
.if ${PORT_OPTIONS:MDOXYGEN}
	@${FIND} -P ${STAGEDIR}${DOCSDIR}/html -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
	@${FIND} -P -d ${STAGEDIR}${DOCSDIR}/ -type d 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/|@dirrmtry |p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
