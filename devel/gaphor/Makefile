# Created by: rehsack@liwing.de
# $FreeBSD$

PORTNAME=	gaphor
PORTVERSION=	0.17.2
CATEGORIES=	devel gnome
MASTER_SITES=	CHEESESHOP/source/e/etk.docking:docking \
		CHEESESHOP/source/g/gaphas:gaphas \
		CHEESESHOP/source/s/simplegeneric:sgeneric \
		CHEESESHOP
DISTFILES=	${DOCKING_DISTNAME}${EXTRACT_SUFX}:docking \
		${GAPHAS_DISTNAME}${EXTRACT_SUFX}:gaphas \
		${SGENERIC_DISTNAME}.zip:sgeneric \
		${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DOCKING_DISTNAME}${EXTRACT_SUFX} \
		${GAPHAS_DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UML modeling environment written in Python

LICENSE=	GPLv2

EXTRACT_DEPENDS=${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0.10.4:${PORTSDIR}/devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:${PORTSDIR}/devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}zope.component>3.4.0:${PORTSDIR}/devel/py-zope.component

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
INSTALLS_ICONS=	yes

PLIST_SUB=	DOCKING_EGG="${DOCKING_EGG}" GAPHAS_EGG="${GAPHAS_EGG}"

DOCKING_DISTNAME=	etk.docking-0.2
DOCKING_EGG=		${DOCKING_DISTNAME}-py${PYTHON_VER}.egg
GAPHAS_DISTNAME=	gaphas-0.7.2
GAPHAS_EGG=		${GAPHAS_DISTNAME}-py${PYTHON_VER}.egg
SGENERIC_DISTNAME=	simplegeneric-0.8.1

post-extract:
	@${UNZIP_CMD} -qo ${DISTDIR}/${SGENERIC_DISTNAME}.zip -d ${WRKDIR}

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
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${DOCKING_EGG}
	@(cd ${WRKDIR}/${DOCKING_DISTNAME}/lib && ${COPYTREE_SHARE} etk \
		${PYTHONPREFIX_SITELIBDIR}/${DOCKING_EGG})
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${GAPHAS_EGG}
	@(cd ${WRKDIR}/${GAPHAS_DISTNAME} && ${COPYTREE_SHARE} gaphas \
		${PYTHONPREFIX_SITELIBDIR}/${GAPHAS_EGG})
	@(cd ${WRKDIR}/${SGENERIC_DISTNAME} && ${INSTALL_DATA} \
		simplegeneric.py* ${PYTHONPREFIX_SITELIBDIR})
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} gaphor.desktop ${DESKTOPDIR})
.for i in 24 48 96 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/gaphor/ui/pixmaps && ${INSTALL_DATA} \
		gaphor-${i}x${i}.png \
		${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gaphor.png)
.endfor

.include <bsd.port.mk>
