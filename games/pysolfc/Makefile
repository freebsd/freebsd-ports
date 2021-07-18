PORTNAME=	pysolfc
DISTVERSION=	2.6.4
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PySolFC/${PYSOLFCDIR} \
		SF/${PORTNAME}/PySolFC-Cardsets/${CARDSETDIR}:cardsets
DISTFILES=	${PYSOLFCDIST} \
		${CARDSETDIST}:cardsets
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Solitaire game, written in Python and the successor of PySol

LICENSE=	GPLv2+ GPLv3+ MIT PCW PD UCP UCJ ULG
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}random2>=0:math/py-random2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PY_PILLOW}

LICENSE_FILE_GPLv3+ =		${WRKSRC}/COPYING
LICENSE_DISTFILES_GPLv3+ =	${PYSOLFCDIST}

LICENSE_FILE_MIT=	${WRKDIR}/${CARDSETDIR}/cardset-spider/COPYRIGHT
LICENSE_DISTFILES_MIT=	${CARDSETDIST}

# This applies also to following cardsets:
# - ${WRKDIR}/${CARDSETDIR}/cardset-rangoon-e/COPYRIGHT
# - ${WRKDIR}/${CARDSETDIR}/cardset-rangoon-r/COPYRIGHT
LICENSE_FILE_PCW=	${WRKDIR}/${CARDSETDIR}/cardset-rangoon-d/COPYRIGHT
LICENSE_NAME_PCW=	Postcardware
LICENSE_PERMS_PCW=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_PCW=	${CARDSETDIST}

LICENSE_FILE_PD=	${WRKDIR}/${CARDSETDIR}/cardset-tksol/COPYRIGHT
LICENSE_DISTFILES_PD=	${CARDSETDIST}

LICENSE_FILE_UCP=	${WRKDIR}/${CARDSETDIR}/cardset-patience/COPYRIGHT
LICENSE_NAME_UCP=	Unknown Copyright / Cardset "Patience"
LICENSE_PERMS_UCP=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_UCP=	${CARDSETDIST}

LICENSE_FILE_UCJ=	${WRKDIR}/${CARDSETDIR}/cardset-jacoby/COPYRIGHT
LICENSE_NAME_UCJ=	Unknown Copyright / Cardset "Jacoby"
LICENSE_PERMS_UCJ=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_UCJ=	${CARDSETDIST}

LICENSE_FILE_ULG=	${WRKDIR}/${CARDSETDIR}/cardset-greywyvern/COPYRIGHT
LICENSE_NAME_ULG=	Unknown License / Cardset "Greywyvern"
LICENSE_PERMS_ULG=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_ULG=	${CARDSETDIST}

# The rest of the cardsets are licensed with the GPLv+2
LICENSE_FILE_GPLv2+ =		${WRKDIR}/${CARDSETDIR}/cardset-1567/COPYRIGHT
LICENSE_DISTFILES_GPLv2+ =	${CARDSETDIST}

USES=		python:3.6+ shebangfix tar:xz
USE_PYTHON=	distutils noflavors autoplist
SHEBANG_FILES=	data/themes/clearlooks/convert_imgs.sh
NO_ARCH=	yes

PLIST_FILES=	share/pixmaps/pysolfc.png
DATADIR=	${PREFIX}/share/PySolFC
WRKSRC=		${WRKDIR}/${PYSOLFCDIR}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

PYSOLFCDIR=	PySolFC-${DISTVERSION}
PYSOLFCDIST=	${PYSOLFCDIR}${EXTRACT_SUFX}
CARDSETDIR=	PySolFC-Cardsets-2.0
CARDSETDIST=	${CARDSETDIR}.tar.bz2

post-patch:
	@${MV} ${WRKSRC}/pysol.py ${WRKSRC}/pysolfc
	@${REINPLACE_CMD} -e 's|pysol.py|pysolfc|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PORTNAME}|' \
		-e 's|^Exec.*|Exec=${PORTNAME}|' \
		${WRKSRC}/data/pysol.desktop
	@${FIND} ${WRKDIR} -name .thumbnails -or -name .xvpics | \
		${XARGS} ${RM} -r
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "s|for l in ('ru', 'ru_RU')|for l in ()|" \
		${WRKSRC}/setup.py

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/pysol01.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKDIR}/${CARDSETDIR} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR}/${CARDSETDIR} && \
		${FIND} . -type f | ${SED} -e 's|^./|${DATADIR_REL}/|' >> ${TMPPLIST})

.include <bsd.port.mk>
