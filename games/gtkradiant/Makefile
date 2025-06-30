PORTNAME=	gtkradiant
PORTVERSION=	1.5.0
PORTREVISION=	20
CATEGORIES=	games cad
MASTER_SITES=	IDSOFTWARE/source/:id \
		http://www.bsd-geek.de/FreeBSD/distfiles/:fb
DISTNAME=	GtkRadiant-GPL
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:id \
		${PORTNAME}_gamepacks${EXTRACT_SUFX}:fb

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Map editor for FPS games, by id Software and Loki Software
WWW=		http://www.qeradiant.com/

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libmhash.so:security/mhash \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gnome pkgconfig python:build scons zip
USE_GNOME=	gdkpixbuf gtk20 libxml2
MAKE_ARGS=	${MAKE_ENV} BUILD=release
SSP_UNSAFE=	yes

DATADIR=	${PREFIX}/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/GPL/GtkRadiant

SUB_FILES=	${PORTNAME}

post-patch:
	@${GREP} -Rl 'defined[[:blank:]]*([[:blank:]]*__linux__[[:blank:]]*) || defined[[:blank:]]*([[:blank:]]*__APPLE__[[:blank:]]*)' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e \
		's/\(defined[[:blank:]]*([[:blank:]]*__linux__[[:blank:]]*) || defined[[:blank:]]*([[:blank:]]*__APPLE__[[:blank:]]*)\)/\1 || defined (__FreeBSD__)/'
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/libs/os/dir.h \
		${WRKSRC}/libs/gtkutil/idledraw.h \
		${WRKSRC}/libs/gtkutil/cursor.h \
		${WRKSRC}/libs/convert.h \
		${WRKSRC}/plugins/shaders/shaders.cpp \
		${WRKSRC}/plugins/vfspk3/vfs.cpp \
		${WRKSRC}/radiant/feedback.h \
		${WRKSRC}/radiant/environment.cpp \
		${WRKSRC}/radiant/patch.cpp \
		${WRKSRC}/radiant/watchbsp.cpp \
		${WRKSRC}/tools/quake3/common/inout.c
# Fix the build against Clang and possibly other modern compilers
	@${REINPLACE_CMD} -e 's,register ,,g' \
		${WRKSRC}/libs/container/hashfunc.h \
		${WRKSRC}/libs/jpeg6/jdcolor.cpp \
		${WRKSRC}/libs/jpeg6/jdhuff.* \
		${WRKSRC}/libs/jpeg6/jdsample.cpp \
		${WRKSRC}/libs/jpeg6/jutils.cpp
	@${REINPLACE_CMD} -e '/#include "generic\/reference\.h"/x ; 318G' \
		${WRKSRC}/libs/scenelib.h
	@${REINPLACE_CMD} -e '/#include "generic\/referencecounted\.h/ { \
		x ; s/^/#include "scenelib.h"/ ; G ; }' \
			${WRKSRC}/plugins/mapq3/parse.h
# Fix warnings of "GtkSpinButton: setting an adjustment with non-zero
# page size is deprecated" (very annoying)
	@${GREP} -Rl --null gtk_adjustment_new ${WRKSRC} | ${XARGS} -0 \
		${REINPLACE_CMD} -E 's|(gtk_adjustment_new[^)]*,)[^)]*|\1 0|'
# Do not #include <sys/dir.h> header which is deprecated
	@${REINPLACE_CMD} -e '/#include/s,<sys/dir,&ent,' \
		${WRKSRC}/tools/quake2/qdata/qdata.c
# Cope with -fno-common being the default in some new compilers
	@${REINPLACE_CMD} -e '/\*CalcTextureReflectivity/s,^void,extern &,' \
		${WRKSRC}/tools/quake2/q2map/qrad.h
	@${REINPLACE_CMD} -E 's,^char[[:blank:]]+outbase,extern &,' \
		${WRKSRC}/tools/quake2/q2map/qvis.c
	@${REINPLACE_CMD} -e '/materialtypes/s,^materialtype_t,extern &,' \
		${WRKSRC}/tools/quake2/qdata_heretic2/common/qfiles.h
	@${REINPLACE_CMD} -e '/\*byteimage, \*lbmpalette/,+5d' \
		${WRKSRC}/tools/quake2/qdata_heretic2/book.c
	@${REINPLACE_CMD} -e '/g_frames/s,^frame_t,extern &,' \
		${WRKSRC}/tools/quake2/qdata_heretic2/models.c
	@${REINPLACE_CMD} -e '/verbose;/d' \
		${WRKSRC}/tools/quake3/q3map2/q3map2.h
	@${REINPLACE_CMD} -e '/c_portalskip, c_leafskip/,+1d' \
		${WRKSRC}/tools/quake3/q3map2/visflow.c

pre-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py
	${CP} -a ${WRKDIR}/${PORTNAME}_gamepacks/* ${WRKSRC}/install

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/install/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
