# New ports collection makefile for:	tortoisehg2
# Date created:		7 May 2011
# Whom:			arrowdodger <6yearold@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tortoisehg
PORTVERSION=	2.1.4
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	thg script from TortoiseHG

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
		${PYTHON_SITELIBDIR}/iniparse/ini.py:${PORTSDIR}/devel/py-iniparse \
		pygmentize:${PORTSDIR}/textproc/py-pygments

OPTIONS=	NAUTILUS "Install TortoiseHG Nautilus extension" off

CONFLICTS=	tortoisehg-1*
LATEST_LINK=	${PORTNAME}2

INSTALLS_ICONS=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.if defined(WITHOUT_NAUTILUS)
PLIST_SUB+=	NAUTILUS="@comment "
.else
PLIST_SUB+=	NAUTILUS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/_path/ s|/usr|${PREFIX}|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/thg
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's/^%%NLS%%/# /' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NLS%%//' ${WRKSRC}/${PYSETUP}
.endif
.if defined(WITHOUT_NAUTILUS)
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%/# /' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%//' ${WRKSRC}/${PYSETUP}
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
