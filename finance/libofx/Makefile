# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$

PORTNAME=	libofx
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml++-2.6.so:textproc/libxml++26 \
		libosp.so:textproc/opensp

USES=		gmake iconv pkgconfig pathfix libtool
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} -f ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
