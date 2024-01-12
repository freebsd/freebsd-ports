PORTNAME=	libjodycode
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tom@hur.st
COMMENT=	Shared code used by several utilities written by Jody Bruchon
WWW=		https://github.com/jbruchon/libjodycode

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jbruchon

MAJOR_VERSION=	${DISTVERSION:C/([0-9]).*/\1/1}

PLIST_FILES=	include/libjodycode.h \
		lib/libjodycode.a \
		lib/libjodycode.so \
		lib/libjodycode.so.${DISTVERSION} \
		lib/libjodycode.so.${MAJOR_VERSION} \
		share/man/man7/libjodycode.7.gz

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.7 ${STAGEDIR}${PREFIX}/share/man/man7
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}.h
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.a
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${PORTNAME}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.${MAJOR_VERSION}
	${LN} -sf ${PORTNAME}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

.include <bsd.port.mk>
