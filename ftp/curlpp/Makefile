# Created by: ijliao
# $FreeBSD$

PORTNAME=	curlpp
PORTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ wrapper for libcurl

LICENSE=	MIT

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	BOOST DOCS EXAMPLES

CONFIGURE_ARGS=	--disable-ewarning
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		pathfix

BOOST_BUILD_DEPENDS=	boost-libs>=1.20.0:${PORTSDIR}/devel/boost-libs
BOOST_RUN_DEPENDS=	${BOOST_BUILD_DEPENDS}
BOOST_CONFIGURE_ON=	--with-boost=${LOCALBASE}
BOOST_CONFIGURE_OFF=	--without-boost

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| -lstdc++||' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/README ${WRKSRC}/examples/example*.cpp ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
