# $FreeBSD$

PORTNAME=	ukncbtl
DISTVERSION=	g20191117
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	UKNC (Elektronika MS-0511) emulator

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5

USE_GL=		gl
USE_QT=		core gui multimedia network script testlib widgets \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	nzeemin
GH_PROJECT=	ukncbtl-qt
GH_TAGNAME=	20b5f043

DESKTOP_ENTRIES=	"UkncBtl" \
			"" \
			"" \
			"${PORTNAME}" \
			"" \
			true

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} '/^#include/s,malloc.h,stdlib.h,' ${WRKSRC}/stdafx.h
	${REINPLACE_CMD} '/^TARGET/s,QtUkncBtl,${PORTNAME},' ${WRKSRC}/QtUkncBtl.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
