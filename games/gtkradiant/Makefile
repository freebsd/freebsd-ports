# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkradiant
PORTVERSION=	1.5.0
PORTREVISION=	9
CATEGORIES=	games cad
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/:id|} \
		http://www.bsd-geek.de/FreeBSD/distfiles/:fb
DISTNAME=	GtkRadiant-GPL
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:id \
		${PORTNAME}_gamepacks${EXTRACT_SUFX}:fb

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Map editor for FPS games, by id Software and Loki Software

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libmhash.so:${PORTSDIR}/security/mhash \
		libpng15.so:${PORTSDIR}/graphics/png

SSP_UNSAFE=	yes
USES=		pkgconfig zip
USE_GNOME=	gtk20 libxml2
USE_PYTHON_BUILD=	yes
USE_SCONS=	yes
SCONS_ARGS=	${MAKE_ENV} BUILD=release

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
# Fix the build against Clang
	@${REINPLACE_CMD} -e '/#include "generic\/reference\.h"/x ; 318G' \
		${WRKSRC}/libs/scenelib.h
	@${REINPLACE_CMD} -e '/#include "generic\/referencecounted\.h/ { \
		x ; s/^/#include "scenelib.h"/ ; G ; }' \
			${WRKSRC}/plugins/mapq3/parse.h
# Fix warnings of "GtkSpinButton: setting an adjustment with non-zero
# page size is deprecated" (very annoying)
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} \
		-E 's|(gtk_adjustment_new[^)]*,)[^)]*|\1 0|'

pre-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py
	${CP} -a ${WRKDIR}/${PORTNAME}_gamepacks/* ${WRKSRC}/install

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/install/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
