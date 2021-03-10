# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.1.1
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO

USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org
GL_ACCOUNT=	BC/public
GL_COMMIT=	faaa895862165acde6df8add722ba4f85a25007d

post-configure:
	${SED} 's|@prefix@|${PREFIX}|g ; s|@exec_prefix@|$${prefix}|g ; \
	  s|@libdir@|$${prefix}/lib|g ; s|@includedir@|$${prefix}/include|g ; \
	  s|@PACKAGE_VERSION@|${PORTVERSION}|g' \
	    ${WRKSRC}/libbcg729.pc.in > ${WRKSRC}/libbcg729.pc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libbcg729.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
