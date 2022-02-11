PORTNAME=	ldview
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LDraw model viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../license.txt

LIB_DEPENDS=	lib3ds.so:graphics/lib3ds \
		libgl2ps.so:print/gl2ps \
		libOSMesa.so:graphics/libosmesa \
		libpng16.so:graphics/png \
		libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	bash:shells/bash \
		ldraw>0:cad/ldraw

USES=		desktop-file-utils gl gmake jpeg qmake qt:5 shared-mime-info shebangfix xorg
USE_QT=		core gui linguist opengl printsupport widgets buildtools_build qmake_build
USE_GL=		gl glu
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	tcobbs

SHEBANG_FILES=	desktop/ldraw-thumbnailer

WRKSRC_SUBDIR=	QT

QMAKE_ARGS=	MANDIR=${PREFIX}/man CONFIG+=EXPORT_3DS

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/share/ldraw"|"${PREFIX}/share/ldraw"|' ${WRKSRC}/ModelViewerWidget.cpp

pre-configure:
	@cd ${WRKSRC} && ${LRELEASE} LDView.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/LDView

.include <bsd.port.mk>
