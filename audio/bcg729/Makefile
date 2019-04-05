# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://linphone.org/releases/sources/bcg729/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO

post-configure:
	${SED} 's|@prefix@|${PREFIX}|g ; s|@exec_prefix@|$${prefix}|g ; \
	  s|@libdir@|$${prefix}/lib|g ; s|@includedir@|$${prefix}/include|g ; \
	  s|@PACKAGE_VERSION@|${PORTVERSION}|g' \
	    ${WRKSRC}/libbcg729.pc.in > ${WRKSRC}/libbcg729.pc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libbcg729.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
