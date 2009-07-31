# New ports collection makefile for:	gtkradiant
# Date created:				9 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gtkradiant
PORTVERSION=	1.5.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/:id|} \
		http://www.bsd-geek.de/FreeBSD/distfiles/:fb
DISTNAME=	GtkRadiant-GPL
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:id \
		${PORTNAME}_gamepacks${EXTRACT_SUFX}:fb

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Level design program developed by id Software and Loki Software

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libsvn/__init__.py:${PORTSDIR}/devel/py-subversion
LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		mhash.2:${PORTSDIR}/security/mhash \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/GPL/GtkRadiant

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

post-build:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py
	${CP} -R ${WRKDIR}/${PORTNAME}_gamepacks/* ${WRKSRC}/install

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/install/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
