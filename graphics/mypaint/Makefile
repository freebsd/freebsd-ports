# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast painting/scribbling program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/cairo:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf
LIB_DEPENDS=	libjson-c.so:${PORTSDIR}/devel/json-c \
		liblcms2.so:${PORTSDIR}/graphics/lcms2
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		swig:${PORTSDIR}/devel/swig13 \
		protoc:${PORTSDIR}/devel/protobuf

USE_GNOME=	glib20 pygtk2
MAKE_ARGS=	prefix="${PREFIX}"
USES=		gettext pkgconfig scons tar:bzip2 python
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
