PORTNAME=	redasm
PORTVERSION=	2.1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Interactive, multiarchitecture disassembler

LICENSE=	GPLv3

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		buildtools_build qmake_build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	REDasmOrg
GH_PROJECT=	REDasm
GH_TUPLE=	REDasmOrg:REDasm-Library:b59bdc3:libra/LibREDasm \
		Dax89:QHexView:4524ca3:qhv/QHexView \
		aquynh:capstone:4948fd1:cs/LibREDasm/depends/capstone

PLIST_FILES=	bin/REDasm lib/LibREDasm.so bin/redasm

post-patch:
	@${REINPLACE_CMD} -e '/Git/s,find_package,#&, ; \
		s|unknown|8848416|' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/REDasm ${STAGEDIR}${PREFIX}/bin
	${LN} -s REDasm ${STAGEDIR}${PREFIX}/bin/redasm
	${INSTALL_LIB} ${BUILD_WRKSRC}/LibREDasm.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
