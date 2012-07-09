# ex:ts=8
# Ports collection makefile for:	curlpp
# Date created:			Nov 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	curlpp
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A C++ wrapper for libcurl

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	BOOST DOCS EXAMPELS

CONFIGURE_ARGS=	--disable-ewarning
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOOST}
BUILD_DEPENDS+=	boost-libs>=1.20.0:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS+=	boost-libs>=1.20.0:${PORTSDIR}/devel/boost-libs
CONFIGURE_ARGS+=--with-boost=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-boost
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/README ${WRKSRC}/examples/example*.cpp ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
