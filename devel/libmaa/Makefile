# Created by: chinsan
# $FreeBSD$

PORTNAME=	libmaa
PORTVERSION=	1.3.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions

# The software was licensed as GPLv2. LGPL20 is for the library.
LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool:build

DOCS=		README doc/libmaa.600dpi.ps
PLIST_FILES=	include/maa.h \
		lib/libmaa.a \
		lib/libmaa.so \
		lib/libmaa.so.3 \
		lib/libmaa.so.3.0.0
PORTDOCS=	${DOCS:T}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmaa.so.3

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
