# Created by: ijliao
# $FreeBSD$

PORTNAME=	pythoncad
PORTVERSION=	37
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/R${PORTVERSION}%20PyGtk/Source
DISTNAME=	PythonCAD-DS1-R${PORTVERSION}

MAINTAINER=	fbsd-ports@xbsd.net
COMMENT=	An open-source CAD package built designed around Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PythonCAD
PYDISTUTILS_PKGVERSION=	DS1-R${PORTVERSION}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/PythonCAD/Generic/preferences.py \
		${WRKSRC}/PythonCAD/Interface/Gtk/gtkimage.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${PREFIX}/bin/gtkpycad
	${INSTALL_DATA} ${WRKSRC}/gtkpycad.png ${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/etc/pythoncad
	${INSTALL_DATA} ${WRKSRC}/prefs.py ${PREFIX}/etc/pythoncad/prefs.py.sample

.include <bsd.port.mk>
