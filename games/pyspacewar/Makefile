PORTNAME=	pyspacewar
DISTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Game loosely based on the original Spacewar!
WWW=		https://pypi.org/project/pyspacewar \
		https://github.com/mgedmin/pyspacewar

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYGAME}

USES=		gnome python
USE_PYTHON=	distutils

NO_ARCH=	yes

post-install:
.for i in 16 22 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/icons/${PORTNAME}${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/icons/${PORTNAME}${i}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}${i}.svg
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/icons/${PORTNAME}32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rst \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
