# Created by: ijliao
# $FreeBSD$

PORTNAME=	curlpp
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	ftp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ wrapper for libcurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

OPTIONS_DEFINE=	BOOST DOCS EXAMPLES

CONFIGURE_ARGS=	--disable-ewarning
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool localbase pathfix

PORTDOCS=	*
PORTEXAMPLES=	*

GH_ACCOUNT=	jpbarrette
USE_GITHUB=	yes

BOOST_BUILD_DEPENDS=	boost-libs>=1.20.0:devel/boost-libs
BOOST_RUN_DEPENDS=	${BOOST_BUILD_DEPENDS}
BOOST_CONFIGURE_ON=	--with-boost=${LOCALBASE}
BOOST_CONFIGURE_OFF=	--without-boost

post-patch:
	@${REINPLACE_CMD} -e 's| -lstdc++||' ${WRKSRC}/configure.ac

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/README ${WRKSRC}/examples/example*.cpp ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
