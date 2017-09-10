# $FreeBSD$

PORTNAME=	gmic
PORTVERSION=	1.6.9
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://gmic.eu/files/source/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GREYC's Magic Image Converter

LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick \
		libIlmImf.so:graphics/OpenEXR \
		libopencv_legacy.so:graphics/opencv \
		libMagick++-6.so:graphics/ImageMagick \
		libavcodec.so:multimedia/ffmpeg \
		libfftw3.so:math/fftw3 \
		libgimp-2.0.so:graphics/gimp-app

OPTIONS_DEFINE=	BASH
OPTIONS_SUB=	yes
BASH_RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		dos2unix gmake localbase pkgconfig
USE_GCC=	yes
USE_GNOME=	gtk20
USE_XORG=	x11 xext xrandr
DOS2UNIX_FILES=	Makefile

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

CFLAGS:=	${CFLAGS:N-O*:N-pipe}
CXXFLAGS:=	${CXXFLAGS:N-O*:N-pipe}
DOTLESS_VER=	${PORTVERSION:S/.//g}

PLIST_FILES=	bin/gmic \
		man/man1/gmic.1.gz \
		%%BASH%%etc/bash_completion.d/gmic \
		%%PLUGIN_DIR%%/gmic_gimp \
		%%PLUGIN_DIR%%/cli_update${DOTLESS_VER}.gmic \
		%%PLUGIN_DIR%%/gimp_update${DOTLESS_VER}.gmic

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	gmic_in_script.scm gmic_use_lib.cpp

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${PREFIX}#g' \
		-e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gmic_gimp ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/../resources/cli_update${DOTLESS_VER}.gmic \
		${WRKSRC}/../resources/gimp_update${DOTLESS_VER}.gmic \
		${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gmic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../man/gmic.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_SCRIPT} ${WRKSRC}/../resources/gmic_bashcompletion.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/gmic

.include <bsd.port.mk>
