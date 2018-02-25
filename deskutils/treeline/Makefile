# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	treeline
PORTVERSION=	2.0.2
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/:treeline \
		http://treeline.bellz.org/plugins2/:plugins
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:treeline
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Structured information storage program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	aspell:textproc/aspell
RUN_DEPENDS=	aspell:textproc/aspell

USES=		python:3.4+ pyqt:4 shebangfix
SHEBANG_FILES=	source/treeline.py
USE_PYQT=	gui network sip_build
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/TreeLine

DESKTOP_ENTRIES=	"TreeLine" "" "${DATADIR}/icons/tree/treeline.png" \
			"${PORTNAME}" "Utility;" false

OPTIONS_DEFINE=		DOCS PLUGINS
OPTIONS_SUB=		yes

PLUGINS_DESC=		Additional plugins: httpload, treepadexport, updateref
PLUGINS_DISTFILES=	httpload.py:plugins \
			treepadexport.py:plugins \
			updateref.py:plugins \

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${STAGEDIR} -p ${PREFIX} \
		-d ${DOCSDIR} -i ${DATADIR}/icons)

do-install-PLUGINS-on:
	(cd ${DISTDIR} && ${INSTALL_DATA} ${PLUGINS_DISTFILES:S/:plugins//} \
		${STAGEDIR}${DATADIR}/plugins)

.include <bsd.port.mk>
