# Created by: Marcus von Appen
# $FreeBSD$

PORTNAME=	pysolfc
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PySolFC/PySolFC-${PORTVERSION} \
		SF/${PORTNAME}/PySolFC-Cardsets/PySolFC-Cardsets-${PORTVERSION}:cardsets
DISTFILES=	PySolFC-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Solitaire game, written in Python and the successor of PySol

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	PySolFC

DATADIR=	${PREFIX}/share/PySolFC
WRKSRC=		${WRKDIR}/PySolFC-${PORTVERSION}
PORTDOCS=	README

CARDSET_DUPS=	2000 crystal-mahjongg dashavatara-ganjifa dondorf \
		gnome-mahjongg-1 hexadeck kintengu matrix mughal-ganjifa \
		oxymoron standard tuxedo vienna-2k

OPTIONS_DEFINE=	CARDSETS DOCS NLS
CARDSETS_DESC=	Install additional cardsets


NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCARDSETS}
DISTFILES+=	PySolFC-Cardsets-${DISTVERSION}${EXTRACT_SUFX}:cardsets
PLIST_SUB+=	CARDSETS=""
.else
PLIST_SUB+=	CARDSETS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${MV} ${WRKSRC}/pysol.py ${WRKSRC}/pysolfc
	@${REINPLACE_CMD} -e 's|pysol.py|pysolfc|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PORTNAME}|' \
		-e 's|^Exec.*|Exec=${PORTNAME}|' \
		${WRKSRC}/data/pysol.desktop
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e "s|for l in ('ru', 'ru_RU')|for l in ()|" \
		${WRKSRC}/setup.py
.endif
	@${FIND} ${WRKDIR} -name .thumbnails -or -name .xvpics | \
		${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC} -name "*.bak" -delete


post-install:
	${LN} -sf ${PREFIX}/share/icons/pysol01.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
.if ${PORT_OPTIONS:MCARDSETS}
.for cdir in ${CARDSET_DUPS}
	@${RM} -rf ${WRKDIR}/PySolFC-Cardsets-${PORTVERSION}/cardset-${cdir}
.endfor
	@cd ${WRKDIR}/PySolFC-Cardsets-${PORTVERSION} && \
		${COPYTREE_SHARE} \* ${DATADIR}
	@cd ${WRKDIR}/PySolFC-Cardsets-${PORTVERSION} && \
		${FIND} . -type f | ${SED} -e 's|^./|${DATADIR_REL}/|' >> ${TMPPLIST}
	@cd ${WRKDIR}/PySolFC-Cardsets-${PORTVERSION} && \
		${FIND} . -type d -mindepth 1 | ${SORT} -r | \
		${SED} -e 's|^./|@dirrm ${DATADIR_REL}/|' >> ${TMPPLIST}
.endif
	@${ECHO} '@dirrm ${DATADIR_REL}' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
