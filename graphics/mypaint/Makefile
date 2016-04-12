# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		swig:devel/swig13 \
		protoc:devel/protobuf

USE_GNOME=	glib20 pygtk2
MAKE_ARGS=	prefix="${PREFIX}"
# XXX gcc-c++11-lib to fix runtime issues with old -lgcc_s and Clang
USES=		compiler:gcc-c++11-lib gettext pkgconfig scons tar:bzip2 python
INSTALLS_ICONS=	yes

SUB_FILES=	pkg-install

post-patch:
	${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/brushlib/operationqueue.c \
		${WRKSRC}/brushlib/fifo.c
	@${REINPLACE_CMD} 's|-O3||g; s|-g||g' \
		${WRKSRC}/SConstruct

pre-install:
	@${RM} -rf ${WRKSRC}/sandbox 2>/dev/null || true
	@cd ${WRKSRC}; ${MAKE_CMD} ${MAKE_ARGS} --install-sandbox=pre-stage

do-install:
.for d in . po brushlib brushlib/po
	@cd ${WRKSRC}/${d}/pre-stage; ${PAX} -rw . ${STAGEDIR}
.endfor

.include <bsd.port.mk>
