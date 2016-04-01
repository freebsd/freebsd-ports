# Created by: rehsack@liwing.de
# $FreeBSD$

PORTNAME=	gaphor
PORTVERSION=	0.17.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	CHEESESHOP/source/e/etk.docking:docking \
		CHEESESHOP/source/g/gaphas:gaphas \
		CHEESESHOP/source/s/simplegeneric:sgeneric \
		CHEESESHOP
DISTFILES=	${DOCKING_DISTNAME}${EXTRACT_SUFX}:docking \
		${GAPHAS_DISTNAME}${EXTRACT_SUFX}:gaphas \
		${SGENERIC_DISTNAME}.zip:sgeneric \
		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UML modeling environment written in Python

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0.10.4:devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}zope.component>3.4.0:devel/py-zope.component

USE_GNOME=	pygtk2
USES=		python
USE_PYTHON=	distutils autoplist
INSTALLS_ICONS=	yes

PLIST_SUB=	DOCKING_EGG="${DOCKING_EGG}" GAPHAS_EGG="${GAPHAS_EGG}"

DOCKING_DISTNAME=	etk.docking-0.2
GAPHAS_DISTNAME=	gaphas-0.7.2
SGENERIC_DISTNAME=	simplegeneric-0.8.1
HICOLORDIR=		${STAGEDIR}${PREFIX}/share/icons/hicolor

post-patch:
	@${REINPLACE_CMD} -e \
		's|\(Icon=gaphor\).*|\1|' ${WRKSRC}/gaphor.desktop

post-build:
	@${PYTHON_CMD} -m compileall ${WRKDIR}/${DOCKING_DISTNAME}/lib/etk
	@${PYTHON_CMD} -O -m compileall ${WRKDIR}/${DOCKING_DISTNAME}/lib/etk
	@${PYTHON_CMD} -m compileall ${WRKDIR}/${GAPHAS_DISTNAME}/gaphas
	@${PYTHON_CMD} -O -m compileall ${WRKDIR}/${GAPHAS_DISTNAME}/gaphas
	@${PYTHON_CMD} -m compileall ${WRKDIR}/${SGENERIC_DISTNAME}
	@${PYTHON_CMD} -O -m compileall ${WRKDIR}/${SGENERIC_DISTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/etk \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gaphas \
		${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKDIR}/${DOCKING_DISTNAME}/lib && ${COPYTREE_SHARE} etk \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/)
	(cd ${WRKDIR}/${GAPHAS_DISTNAME} && ${COPYTREE_SHARE} gaphas \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/)
	(cd ${WRKDIR}/${SGENERIC_DISTNAME} && ${INSTALL_DATA} \
		simplegeneric.py* ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} gaphor.desktop \
		${STAGEDIR}${DESKTOPDIR})
.for i in 24 48 96 256
	@${MKDIR} ${HICOLORDIR}/${i}x${i}/apps
	(cd ${WRKSRC}/gaphor/ui/pixmaps && ${INSTALL_DATA} \
		gaphor-${i}x${i}.png ${HICOLORDIR}/${i}x${i}/apps/gaphor.png)
.endfor

.include <bsd.port.mk>
