# $FreeBSD$

PORTNAME=	tortoisehg
PORTVERSION=	2.8.2
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	THg script from TortoiseHG

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.3:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=4.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.3:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.3:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.8.3:${PORTSDIR}/textproc/py-qt4-xml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.3:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=4.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.3:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.3:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}iniparse>0:${PORTSDIR}/devel/py-iniparse \
		pygmentize:${PORTSDIR}/textproc/py-pygments

OPTIONS_DEFINE=	NAUTILUS
NAUTILUS_DESC=	Install TortoiseHG Nautilus extension

INSTALLS_ICONS=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
.endif

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
	${MKDIR} ${PREFIX}/share/tortoisehg
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${PREFIX}/share/tortoisehg/
	${INSTALL_DATA} ${WRKSRC}/contrib/tortoisehg.desktop ${PREFIX}/share/applications/

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
