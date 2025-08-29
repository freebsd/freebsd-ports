PORTNAME=	pysolfc
DISTVERSION=	3.4.1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PySolFC/${PYSOLFCDIR} \
		SF/${PORTNAME}/PySolFC-Cardsets/minimal/:cardsets \
		SF/${PORTNAME}/PySol-Music/${MUSICDIR}/:music
DISTFILES=	${PYSOLFCDIST} \
		${CARDSETDIST}:cardsets \
		${MUSICDIST}:music
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Solitaire game, written in Python and the successor of PySol
WWW=		https://pysolfc.sourceforge.io/

LICENSE=	GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =		${WRKDIR}/${CARDSETDIR}/cardset-2000/COPYRIGHT
LICENSE_FILE_GPLv3+ =		${WRKSRC}/COPYING
LICENSE_DISTFILES_GPLv2+ =	${CARDSETDIST} ${MUSICDIST}
LICENSE_DISTFILES_GPLv3+ =	${PYSOLFCDIST}

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysol-cards>0:games/py-pysol-cards@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python shebangfix tar:xz
USE_PYTHON=	autoplist noflavors pep517
SHEBANG_FILES=	data/themes/clearlooks/convert_imgs.sh
NO_ARCH=	yes

PLIST_FILES=	share/pixmaps/pysolfc.png
DATADIR=	${PREFIX}/share/PySolFC
WRKSRC=		${WRKDIR}/${PYSOLFCDIR}

OPTIONS_DEFINE=	NLS PILLOW SOUND
OPTIONS_DEFAULT=	PILLOW SOUND
OPTIONS_SUB=	yes

PILLOW_DESC=	Enhanced graphics support

NLS_USES=	gettext

PILLOW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
SOUND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game@${PY_FLAVOR}

PYSOLFCDIR=	PySolFC-${DISTVERSION}
PYSOLFCDIST=	${PYSOLFCDIR}${EXTRACT_SUFX}
CARDSETDIR=	PySolFC-Cardsets--Minimal-3.1.0
CARDSETDIST=	${CARDSETDIR}.tar.xz
MUSICDIR=	PySol-Music-4.50
MUSICDIST=	${MUSICDIR:tl}.tar.xz

post-patch:
	@${MV} ${WRKSRC}/pysol.py ${WRKSRC}/pysolfc
	@${REINPLACE_CMD} -e 's|pysol.py|pysolfc|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PORTNAME}|' \
		-e 's|^Exec.*|Exec=${PORTNAME}|' \
		${WRKSRC}/data/pysol.desktop
	@${FIND} ${WRKDIR} -name .thumbnails -or -name .xvpics | \
		${XARGS} ${RM} -r
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|^#%%NLS%%||' ${WRKSRC}/setup.py

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/pysol.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKDIR}/${CARDSETDIR} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR}/${CARDSETDIR} && \
		${FIND} . -type f | ${SED} -e 's|^./|${DATADIR_REL}/|' >> ${TMPPLIST})

post-install-SOUND-on:
	(cd ${WRKDIR}/${MUSICDIR:tl}/data && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR}/${MUSICDIR:tl}/data && \
		${FIND} . -type f | ${SED} -e 's|^./|${DATADIR_REL}/|' >> ${TMPPLIST})

.include <bsd.port.mk>
