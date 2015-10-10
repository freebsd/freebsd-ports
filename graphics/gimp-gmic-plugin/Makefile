# $FreeBSD$

PORTNAME=	gmic
PORTVERSION=	1.6.0.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/older_versions/ \
		SF/${PORTNAME}/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GREYC's Magic Image Converter

LIB_DEPENDS=	libGraphicsMagick++.so:${PORTSDIR}/graphics/GraphicsMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libMagick++-6.so:${PORTSDIR}/graphics/ImageMagick \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

OPTIONS_DEFINE=	BASH
OPTIONS_SUB=	yes
BASH_RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		gmake pkgconfig
USE_GCC=	yes
USE_GNOME=	gtk20
USE_XORG=	x11 xext xrandr

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-O*:N-pipe}
CXXFLAGS:=	${CXXFLAGS:N-O*:N-pipe}

PLIST_FILES=	bin/gmic \
		man/man1/gmic.1.gz \
		%%BASH%%etc/bash_completion.d/gmic_bashcompletion.sh \
		%%PLUGIN_DIR%%/gmic_gimp

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	gmic_in_script.scm gmic_use_lib.cpp

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${PREFIX}#g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gmic_gimp ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gmic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../man/gmic.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MBASH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_SCRIPT} ${WRKSRC}/../resources/gmic_bashcompletion.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
.endif

.include <bsd.port.mk>
