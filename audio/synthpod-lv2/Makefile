PORTNAME=	synthpod
PORTVERSION=	g20230521
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Nonlinear LV2 Plugin Container
WWW=		https://git.open-music-kontrollers.ch/~hp/synthpod

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_DEPENDS=	git:devel/git
BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsratom-0.so:audio/sratom \
		libxcb-xrm.so:x11/xcb-util-xrm

USES=		meson compiler:c++11-lib pkgconfig localbase
USE_CXXSTD=	c++11

GIT_URL=	https://git.open-music-kontrollers.ch/~hp/synthpod
GIT_TAGNAME=	8217951d21f53546c7ef7d28ed4143ae43f26d02

MESON_ARGS=	-Duse-alsa=false -Duse-qt4=false

OPTIONS_DEFINE=		JACK DUMMY
OPTIONS_DEFAULT=	JACK X11
OPTIONS_GROUP=		UI
OPTIONS_GROUP_UI=	X11 GTK2 GTK3 QT
OPTIONS_SUB=		yes

DUMMY_DESC=		Build DUMMY standalone host
DUMMY_MESON_OFF=	-Duse-dummy=false
DUMMY_LIB_DEPENDS=	libuv.so:devel/libuv

GTK2_DESC=		Build GTK-2 sandbox
GTK2_MESON_ON=		-Duse-gtk2=true
GTK2_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
GTK2_USES=		gnome xorg
GTK2_USE=		XORG=x11,xcb,xext GNOME=glib20,gtk20,gdkpixbuf2 gettext-runtime

GTK3_DESC=		Build GTK-3 sandbox
GTK3_MESON_ON=		-Duse-gtk3=true
GTK3_USES=		gnome xorg
GTK3_USE=		XORG=x11,xcb,xext GNOME=glib20,gtk30,atk gettext-runtime
GTK3_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm

JACK_DESC=		Build JACK standalone host
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_MESON_OFF=		-Duse-jack=false

QT_DESC=		Build Qt-5 sandbox
QT_MESON_ON=		-Duse-qt5=true
QT_USES=		qt:5 xorg
QT_USE=			qt=core,widgets,buildtools:build xorg=xcb
QT_LIB_DEPENDS=		libxcb-icccm.so:x11/xcb-util-wm

X11_DESC=		Build X11 sandbox
X11_MESON_OFF=		-Duse-x11=false
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libxcb-icccm.so:x11/xcb-util-wm \
			libvterm.so:devel/libvterm
X11_USES=		gl gnome xorg
X11_USE=		GL=glew,opengl XORG=xcb,x11 GNOME=cairo

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    ${ECHO} "==> Fetching from ${GIT_URL} for tag-name=${GIT_TAGNAME}" && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${GIT_TAGNAME} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

.include <bsd.port.mk>
