# New ports collection makefile for:	gdesklets
# Date created:				11 August 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets
PORTVERSION=	0.26.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.pycage.de/download/${PORTNAME}/
DISTNAME=	gDesklets-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	A framework for Gnome 2.x for desktop applets

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
LIB_DEPENDS=	gtop-2.0.2:${PORTSDIR}/devel/libgtop2
RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack lthack

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

MAN1=	gdesklets.1

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/config
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/data
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/desktop
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/display
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/factory
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/libdesklets
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/main
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/sensor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/gdesklets/utils
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
