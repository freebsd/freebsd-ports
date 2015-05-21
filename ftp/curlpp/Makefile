# Created by: ijliao
# $FreeBSD$

PORTNAME=	curlpp
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	ftp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ wrapper for libcurl

LICENSE=	MIT

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	BOOST DOCS EXAMPLES

CONFIGURE_ARGS=	--disable-ewarning
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		autoreconf libtool pathfix

PORTDOCS=	*
PORTEXAMPLES=	*

GH_ACCOUNT=	jpbarrette
USE_GITHUB=	yes

PATHFIX_MAKEFILEIN=	Makefile.am

BOOST_BUILD_DEPENDS=	boost-libs>=1.20.0:${PORTSDIR}/devel/boost-libs
BOOST_RUN_DEPENDS=	${BOOST_BUILD_DEPENDS}
BOOST_CONFIGURE_ON=	--with-boost=${LOCALBASE}
BOOST_CONFIGURE_OFF=	--without-boost

post-patch:
	@${REINPLACE_CMD} -e 's| -lstdc++||' ${WRKSRC}/configure.ac

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/README ${WRKSRC}/examples/example*.cpp ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
