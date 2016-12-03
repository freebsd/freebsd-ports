# $FreeBSD$

PORTNAME=	tortoisehg
PORTVERSION=	4.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/tortoisehg/targz/downloads/
#MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	THg script from TortoiseHG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.11.4:devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.9.1:devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.11.4:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.11.4:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.11.4:textproc/py-qt4-xml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.11.4:devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.9.1:devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.11.4:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.11.4:x11-toolkits/py-qt4-gui \
		hg:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0.4:devel/py-iniparse \
		pygmentize:textproc/py-pygments

OPTIONS_DEFINE=	NAUTILUS NLS
NAUTILUS_DESC=	Install TortoiseHG Nautilus extension
OPTIONS_SUB=	yes

USES=		python:2.7
NLS_USES=	gettext

INSTALLS_ICONS=	yes

USE_PYTHON=	distutils
NO_ARCH=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e '/_path/ s|/usr|${PREFIX}|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/contrib/tortoisehg.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/thg

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's/^%%NLS%%//' ${WRKSRC}/${PYSETUP}

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's/^%%NLS%%/# /' ${WRKSRC}/${PYSETUP}

post-patch-NAUTILUS-on:
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%//' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${PYSETUP}

post-patch-NAUTILUS-off:
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%/# /' ${WRKSRC}/${PYSETUP}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tortoisehg
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${STAGEDIR}${PREFIX}/share/tortoisehg/
	${INSTALL_DATA} ${WRKSRC}/contrib/tortoisehg.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
