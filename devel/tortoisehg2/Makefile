# $FreeBSD$

PORTNAME=	tortoisehg
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	THg script from TortoiseHG

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.10.2:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.7.2:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.10.2:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.10.2:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.20.2:${PORTSDIR}/textproc/py-qt4-xml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.10.2:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.7.2:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.10.2:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.10.2:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0.4:${PORTSDIR}/devel/py-iniparse \
		pygmentize:${PORTSDIR}/textproc/py-pygments

OPTIONS_DEFINE=	NAUTILUS NLS

NLS_USES=	gettext

NAUTILUS_DESC=	Install TortoiseHG Nautilus extension

OPTIONS_SUB=	yes

INSTALLS_ICONS=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/_path/ s|/usr|${PREFIX}|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/contrib/tortoisehg.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/thg
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's/^%%NLS%%//' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NLS%%/# /' ${WRKSRC}/${PYSETUP}
.endif
.if ${PORT_OPTIONS:MNAUTILUS}
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%//' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%/# /' ${WRKSRC}/${PYSETUP}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tortoisehg
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${STAGEDIR}${PREFIX}/share/tortoisehg/
	${INSTALL_DATA} ${WRKSRC}/contrib/tortoisehg.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
