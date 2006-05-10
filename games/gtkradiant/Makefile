# New ports collection makefile for:	gtkradiant
# Date created:				9 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gtkradiant
PORTVERSION=	1.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/:id|} \
		http://www.bsd-geek.de/FreeBSD/distfiles/:fb
DISTNAME=	GtkRadiant-GPL
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:id \
		${PORTNAME}_gamepacks${EXTRACT_SUFX}:fb

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Level design program developed by id Software and Loki Software

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libsvn/__init__.py:${PORTSDIR}/devel/subversion-python \
		scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext \
		mhash.2:${PORTSDIR}/security/mhash \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/GPL/GtkRadiant

USE_ZIP=	yes
USE_GCC=	3.4+
USE_GNOME=	gtk20 libxml2
USE_PYTHON_BUILD=	yes

SUB_FILES=	${PORTNAME}

DATADIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libs__bytestreamutils.h \
		${FILESDIR}/extra-patch-libs__math__vector.h
.endif

post-patch:
.for f in CC CXX CFLAGS LOCALBASE PTHREAD_CFLAGS PTHREAD_LIBS X11BASE
	@${REINPLACE_CMD} -i '' -e 's|%%${f}%%|${${f}}|g' ${WRKSRC}/SConstruct
.endfor
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/SConscript
	@${GREP} -Rl 'defined[[:blank:]]*([[:blank:]]*__linux__[[:blank:]]*) || defined[[:blank:]]*([[:blank:]]*__APPLE__[[:blank:]]*)' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e \
		's/\(defined[[:blank:]]*([[:blank:]]*__linux__[[:blank:]]*) || defined[[:blank:]]*([[:blank:]]*__APPLE__[[:blank:]]*)\)/\1 || defined (__FreeBSD__)/'

do-build:
	cd ${WRKSRC} && scons && ${PYTHON_CMD} install.py
	${CP} -R ${WRKDIR}/${PORTNAME}_gamepacks/* ${WRKSRC}/install

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/install/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
