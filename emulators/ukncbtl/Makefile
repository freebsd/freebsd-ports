PORTNAME=	ukncbtl
DISTVERSION=	g20240813
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	UKNC (Elektronika MS-0511) emulator
WWW=		https://github.com/nzeemin/ukncbtl-doc/wiki

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler:c++11-lang gl qmake qt:5

USE_GL=		gl
USE_QT=		core gui multimedia network script testlib widgets \
		buildtools:build linguisttools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	nzeemin
GH_PROJECT=	ukncbtl-qt
GH_TAGNAME=	ae5021f8

DESKTOP_ENTRIES=	"UkncBtl" \
			"" \
			"${PREFIX}/share/pixmaps/ukncbtl.png" \
			"${PORTNAME}" \
			"" \
			true

WRKSRC_SUBDIR=	emulator

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/ukncbtl.png

post-patch:
	${REINPLACE_CMD} '/^#include/s,malloc.h,stdlib.h,' ${WRKSRC}/stdafx.h
	${REINPLACE_CMD} -e '/^TARGET/s,QtUkncBtl,${PORTNAME},' \
		-e '/^QMAKE_EXTRA_COMPILERS/s,lrelease,,' \
		${WRKSRC}/QtUkncBtl.pro

pre-build:
	(cd ${WRKSRC}/lang && ${LRELEASE} *.ts)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/ukncbtl.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
