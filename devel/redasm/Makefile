# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redasm
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Interactive, multiarchitecture disassembler

LICENSE=	GPLv3

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		buildtools_build qmake_build core gui network webengine
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	REDasmOrg
GH_PROJECT=	REDasm
GH_TUPLE=	REDasmOrg:REDasm-Library:2059871:libra/LibREDasm \
		Dax89:QHexView:e96ea40:qhv/QHexView \
		aquynh:capstone:4948fd1:cs/LibREDasm/depends/capstone

PLIST_FILES=	bin/REDasm lib/LibREDasm.so

post-patch:
	@${REINPLACE_CMD} -e 's,formats\.size(),formatsCount,' \
		${WRKSRC}/mainwindow.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/REDasm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/LibREDasm.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
