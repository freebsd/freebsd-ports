# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linuxcnc
PORTVERSION=	20170708
PORTREVISION=	2
CATEGORIES=	cad
PKGNAMESUFFIX=	-devel

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Open Source CNC machine controller

LICENSE=	GPLv2

BROKEN_FreeBSD_10=	Does not build

LIB_DEPENDS=	libBLT25.so:x11-toolkits/blt \
		libboost_python.so:devel/boost-python-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libmodbus.so:comms/libmodbus \
		libncurses.so:devel/ncurses \
		libXaw.so:x11-toolkits/libXaw \
		libtclx8.4.so:lang/tclX
RUN_DEPENDS=	bash:shells/bash \
		bwidget>=1.4:x11-toolkits/bwidget \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:x11-toolkits/py-vte \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:x11-toolkits/py-gtkglext \
		${LOCALBASE}/lib/Img/libtkimg1.4.6.so:graphics/libimg
BUILD_DEPENDS=	${RUN_DEPENDS}

# Workaround for a clang crash on 12-CURRENT.
BUILD_DEPENDS+=	clang38:lang/clang38
CC=		clang38
CXX=		clang++38

NO_PACKAGE=	Licensing conflict between LinuxCNC (GPL2) and readline (GPL3)

WRKSRC_SUBDIR=	src
PATCH_WRKSRC=	${WRKDIR}/linuxcnc-${GH_TAGNAME}
ALL_TARGET=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-realtime=uspace --enable-non-distributable=yes \
		CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-I${LOCALBASE}/include" CXX="${CXX}" CC="${CC}" \
		--with-locale-dir="${PREFIX}/share/locale" --with-python=${PYTHON_CMD}
MAKE_ENV=	BUILD_VERBOSE=1
USES=		autoreconf gettext gmake ncurses pkgconfig python readline shebangfix tk
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 libgnomeprintui pygtksourceview
USE_XORG=	ice sm x11 xext xft xinerama xmu xrender xscrnsaver xt
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	LinuxCNC
GH_TAGNAME=	5b7929df50e0574cb1105143fffe525916d8a4c2

post-patch:
		${FIND} ${PATCH_WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -i '' \
			-e 's|#!.*/bin/bash|#!${LOCALBASE}/bin/bash|' \
			-e 's|#!.*/usr/bin/tclsh|#!${LOCALBASE}/bin/tclsh8.6|' \
			-e 's|#!.*/usr/bin/wish|#!${LOCALBASE}/bin/wish8.6|' \
			-e 's|#!.*/usr/bin/env python|#!/usr/bin/env python2|' \
			-e 's|#!.*/usr/bin/python|#!/usr/bin/env python2|' \
			-e 's|lib/tcltk|lib/tcllib|'

.include <bsd.port.mk>
