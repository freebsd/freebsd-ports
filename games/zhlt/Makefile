# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zhlt
PORTVERSION=	3.4
CATEGORIES=	games devel
MASTER_SITES=	http://downloads.ammahls.com/zhlt/Old%20SDK%20Code/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}f-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Zoner's Half-Life compile tools

USES=		dos2unix zip
DOS2UNIX_FILES=	common/bspfile.h common/cmdlib.cpp common/mathlib.h \
		common/threads.cpp common/threads.h common/win32fix.h \
		hlbsp/qbsp.cpp hlcsg/brush.cpp hlcsg/brushunion.cpp \
		hlcsg/csg.h hlcsg/qcsg.cpp hlrad/lightmap.cpp \
		hlrad/mathutil.cpp hlrad/qrad.cpp hlrad/qrad.h \
		hlrad/sparse.cpp hlrad/vismatrix.cpp hlrad/vismatrixutil.cpp \
		hlvis/flow.cpp hlvis/vis.cpp hlvis/vis.h

MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/hlbsp bin/hlcsg bin/hlrad bin/hlvis bin/ripent

post-patch:
	@${REINPLACE_CMD} -E 's,(min|max)\(,std::&,g' \
		${WRKSRC}/common/boundingbox.h \
		${WRKSRC}/common/filelib.cpp \
		${WRKSRC}/common/winding.cpp \
		${WRKSRC}/hlrad/lightmap.cpp \
		${WRKSRC}/hlvis/flow.cpp
	@${REINPLACE_CMD} -e 's,min(32,&L,' \
		${WRKSRC}/common/filelib.cpp

.include <bsd.port.mk>
