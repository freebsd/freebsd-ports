# $FreeBSD$

PORTNAME=	anttweakbar
DISTVERSION=	1.16
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	AntTweakBar_${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library to add light and GUI into graphic apps

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/../License.txt

USES=		dos2unix gl xorg zip
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/AntTweakBar
WRKSRC_SUBDIR=	src

DOS2UNIX_FILES=	Makefile

LDFLAGS+=	-L${LOCALBASE}/lib -lX11

BINARY_ALIAS=	gcc=${CC}

PLIST_FILES=	include/AntTweakBar.h \
		lib/libAntTweakBar.a \
		lib/libAntTweakBar.so \
		lib/libAntTweakBar.so.${DISTVERSION:R} \
		lib/libAntTweakBar.so.${DISTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/../include/AntTweakBar.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/../lib/libAntTweakBar.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/../lib/libAntTweakBar.so ${STAGEDIR}${PREFIX}/lib/libAntTweakBar.so.${DISTVERSION}
	cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -s libAntTweakBar.so.${DISTVERSION} libAntTweakBar.so.${DISTVERSION:R} && \
		${LN} -s libAntTweakBar.so.${DISTVERSION} libAntTweakBar.so

.include <bsd.port.mk>
