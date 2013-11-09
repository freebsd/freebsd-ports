# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast painting/scribbling program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/cairo:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf
LIB_DEPENDS=	json:${PORTSDIR}/devel/json-c \
		lcms2:${PORTSDIR}/graphics/lcms2
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		swig:${PORTSDIR}/devel/swig13 \
		protoc:${PORTSDIR}/devel/protobuf

USE_BZIP2=	yes
USE_GNOME=	glib20 pygtk2
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix="${PREFIX}"
USES=		gettext pkgconfig
INSTALLS_ICONS=	yes

SUB_FILES=	pkg-install

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/brushlib/operationqueue.c \
		${WRKSRC}/brushlib/fifo.c
	@${REINPLACE_CMD} 's|-O3||g; s|-g||g' \
		${WRKSRC}/SConstruct

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
