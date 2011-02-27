# New ports collection makefile for:	gimp-gmic-plugin
# Date created:				07 Feb 2011
# Whom:					Mahmatkhanov Ruslan <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gmic
PORTVERSION=	1.4.8.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME} \
		SF/${PORTNAME}/old
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	GREYC's Magic Image Converter

LIB_DEPENDS=	GraphicsMagick++.6:${PORTSDIR}/graphics/GraphicsMagick13 \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		Magick++.4:${PORTSDIR}/graphics/ImageMagick \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		cv.2:${PORTSDIR}/graphics/opencv \
		fftw3.5:${PORTSDIR}/math/fftw3 \
		gimp-2.0:${PORTSDIR}/graphics/gimp-app

OPTIONS=	BASH "Install programmable completions for Bash" off

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_XORG=	x11 xext xrandr

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS:=	${CFLAGS:N-O*:N-pipe}
CXXFLAGS:=	${CXXFLAGS:N-O*:N-pipe}

MAN1=		gmic.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_BASH)
RUN_DEPENDS+=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
PLIST_SUB+=	BASH=""
.else
PLIST_SUB+=	BASH="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${PREFIX}#g' \
		${WRKSRC}/src/Makefile

do-install:
	@${MKDIR} ${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/gmic_gimp ${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/gmic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gmic.1.gz ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html/img
	@${CP} -R ${WRKSRC}/html/*.* ${DOCSDIR}/html
	@(cd ${WRKSRC}/html/img && ${COPYTREE_SHARE} \* ${DOCSDIR}/html/img)
.endif
.if defined(WITH_BASH)
	${INSTALL_SCRIPT} ${WRKSRC}/src/gmic_bashcompletion.sh \
		${PREFIX}/etc/bash_completion.d/gmic_bashcompletion.sh
.endif

.include <bsd.port.post.mk>
