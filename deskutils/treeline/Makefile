# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	treeline
PORTVERSION=	1.4.1
PORTREVISION=	8
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/:treeline \
		http://treeline.bellz.org/plugins/:plugins \
		http://depot.fsck.ch/mirror/distfiles/:treeline,plugins
MASTER_SITE_SUBDIR=treeline/:treeline
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:treeline
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Structured information storage program

LICENSE=	GPLv2

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		aspell:${PORTSDIR}/textproc/aspell

WRKSRC=		${WRKDIR}/TreeLine
USE_QT4=	# empty
USE_PYTHON=	2
NO_BUILD=	yes

DESKTOP_ENTRIES=	"TreeLine" "" "${DATADIR}/icons/tree/treeline.png" \
			"${PORTNAME}" "Utility;" false

OPTIONS_DEFINE=		DOCS HTTPLOAD
OPTIONS_SUB=		yes

HTTPLOAD_DESC=		httpLoad plugin
HTTPLOAD_DISTFILES=	httpload2.py:plugins

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${STAGEDIR} -p ${PREFIX} \
		-d ${DOCSDIR} -i ${DATADIR}/icons)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins
.if ${PORT_OPTIONS:MHTTPLOAD}
	${INSTALL_DATA} ${DISTDIR}/httpload2.py \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins
.endif

.include <bsd.port.mk>
