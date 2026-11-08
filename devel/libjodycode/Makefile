PORTNAME=	libjodycode
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.2
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/jbruchon/libjodycode/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tom@hur.st
COMMENT=	Shared code used by several utilities written by Jody Bruchon
WWW=		https://codeberg.org/jbruchon/libjodycode

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake

USE_LDCONFIG=	yes

_MAJOR_VERSION=	${DISTVERSION:C/([0-9]).*/\1/1}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/libjodycode.h \
		lib/libjodycode.a \
		lib/libjodycode.so \
		lib/libjodycode.so.${_MAJOR_VERSION} \
		lib/libjodycode.so.${DISTVERSION} \
		share/man/man3/libjodycode.3.gz

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.3 ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}.h
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.a
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${PORTNAME}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.${_MAJOR_VERSION}
	${LN} -sf ${PORTNAME}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

.include <bsd.port.mk>
