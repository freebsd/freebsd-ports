# Created by: ijliao
# $FreeBSD$

PORTNAME=	pythoncad
PORTVERSION=	37
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/R${PORTVERSION}%20PyGtk/Source
DISTNAME=	PythonCAD-DS1-R${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source CAD package built designed around Python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2@${FLAVOR}

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	PythonCAD
PYDISTUTILS_PKGVERSION=	DS1-R${PORTVERSION}
NO_ARCH=	yes
SHEBANG_FILES=	gtkpycad.py

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/PythonCAD/Generic/preferences.py \
		${WRKSRC}/PythonCAD/Interface/Gtk/gtkimage.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${STAGEDIR}${PREFIX}/bin/gtkpycad
	${INSTALL_DATA} ${WRKSRC}/gtkpycad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pythoncad
	${INSTALL_DATA} ${WRKSRC}/prefs.py ${STAGEDIR}${PREFIX}/etc/pythoncad/prefs.py.sample

.include <bsd.port.mk>
