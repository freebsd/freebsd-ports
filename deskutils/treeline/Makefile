# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	treeline
PORTVERSION=	1.4.1
PORTREVISION=	9
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/:treeline \
		http://treeline.bellz.org/plugins/:plugins \
		http://depot.fsck.ch/mirror/distfiles/:treeline,plugins
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:treeline
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Structured information storage program

LICENSE=	GPLv2

BUILD_DEPENDS=	aspell:textproc/aspell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:net/py-qt4-network \
		aspell:textproc/aspell

WRKSRC=		${WRKDIR}/TreeLine
USE_QT4=	# empty
USES=		python:2
NO_BUILD=	yes
NO_ARCH=	yes

DESKTOP_ENTRIES=	"TreeLine" "" "${DATADIR}/icons/tree/treeline.png" \
			"${PORTNAME}" "Utility;" false

OPTIONS_DEFINE=		DOCS HTTPLOAD
OPTIONS_SUB=		yes

HTTPLOAD_DESC=		httpLoad plugin
HTTPLOAD_DISTFILES=	httpload2.py:plugins

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${STAGEDIR} -p ${PREFIX} \
		-d ${DOCSDIR} -i ${DATADIR}/icons)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins

do-install-HTTPLOAD-on:
	${INSTALL_DATA} ${DISTDIR}/httpload2.py \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins

.include <bsd.port.mk>
