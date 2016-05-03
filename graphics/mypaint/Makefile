# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+ ISCL MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_ISCL=	${WRKSRC}/brushlib/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.cursors

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		swig:devel/swig13 \
		protoc:devel/protobuf

USE_GITHUB=	yes
USE_GNOME=	glib20 pygtk2
MAKE_ARGS=	prefix="${PREFIX}"
# XXX gcc-c++11-lib to fix runtime issues with old -lgcc_s and Clang
USES=		compiler:gcc-c++11-lib desktop-file-utils gettext \
		pkgconfig python scons tar:bzip2
INSTALLS_ICONS=	yes

SUB_FILES=	pkg-install

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/brushlib/operationqueue.c \
		${WRKSRC}/brushlib/fifo.c
	@${REINPLACE_CMD} 's|-O3||g; s|-g||g' \
		${WRKSRC}/SConstruct

pre-install:
	@${RM} -rf ${WRKSRC}/sandbox 2>/dev/null || ${TRUE}
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} --install-sandbox=pre-stage)

do-install:
.for d in . po brushlib brushlib/po
	(cd ${WRKSRC}/${d}/pre-stage && ${PAX} -rw . ${STAGEDIR})
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mypaint/_mypaintlib.so

.include <bsd.port.mk>
