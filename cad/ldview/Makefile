PORTNAME=	ldview
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LDraw model viewer
WWW=		https://tcobbs.github.io/ldview/

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
USE_GITHUB=	yes
GH_ACCOUNT=	tcobbs
USE_GL=		gl glu
USE_QT=		core gui linguist opengl printsupport widgets buildtools:build qmake:build
USE_XORG=	x11

SHEBANG_FILES=	desktop/ldraw-thumbnailer

QMAKE_ARGS=	CONFIG+=EXPORT_3DS

WRKSRC_SUBDIR=	QT

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/share/ldraw"|"${PREFIX}/share/ldraw"|' ${WRKSRC}/ModelViewerWidget.cpp
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|register ||' ${WRKSRC}/../LDLoader/LDrawIni.c
.endif

pre-configure:
	@cd ${WRKSRC} && ${LRELEASE} LDView.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/LDView

.include <bsd.port.mk>
