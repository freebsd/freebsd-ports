# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$

PORTNAME=	libofx
PORTVERSION=	0.9.9
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libosp.so:${PORTSDIR}/textproc/opensp

USES=		gmake iconv pkgconfig
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	APIDOC
APIDOC_DESC=	Install full API documentation

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README totest.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MAPIDOC}
	@(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif
.endif

.include <bsd.port.mk>
