# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkradiant
PORTVERSION=	1.5.0
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/:id|} \
		http://www.bsd-geek.de/FreeBSD/distfiles/:fb
DISTNAME=	GtkRadiant-GPL
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:id \
		${PORTNAME}_gamepacks${EXTRACT_SUFX}:fb

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Level design program developed by id Software and Loki Software

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libmhash.so:${PORTSDIR}/security/mhash \
		libpng15.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/GPL/GtkRadiant

USES=		pkgconfig
USE_ZIP=	yes
USE_GNOME=	gtk20 libxml2
USE_PYTHON_BUILD=	yes
USE_SCONS=	yes
SCONS_ARGS=	${MAKE_ENV} BUILD=release PTHREAD_LIBS="${PTHREAD_LIBS}"

SUB_FILES=	${PORTNAME}
DATADIR=	${PREFIX}/lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/SConscript
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
	@${REINPLACE_CMD} -e '/#include "generic\/reference.h"/x ; 318G' \
		${WRKSRC}/libs/scenelib.h
	@${REINPLACE_CMD} -e '/#include "generic\/referencecounted.h/ { \
		x ; s/^/#include "scenelib.h"/ ; G ; }' \
			${WRKSRC}/plugins/mapq3/parse.h

post-build:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py
	${CP} -a ${WRKDIR}/${PORTNAME}_gamepacks/* ${WRKSRC}/install

do-install:
	@${MKDIR} ${DATADIR}
	${CP} -a ${WRKSRC}/install/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
