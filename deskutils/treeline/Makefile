# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	treeline
PORTVERSION=	1.4.1
PORTREVISION=	6
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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network

WRKSRC=		${WRKDIR}/TreeLine
USE_QT4=	# empty
USE_PYTHON=	2
NO_BUILD=	yes

DESKTOP_ENTRIES=	"TreeLine" "Structured information storage program" \
			"${DATADIR}/icons/tree/treeline.png" "treeline" \
			"Utility;" false

OPTIONS_DEFINE=		HTTPLOAD
OPTIONS_SINGLE=		SPELLER
OPTIONS_SINGLE_SPELLER=	ASPELL ISPELL

HTTPLOAD_DESC=		httpLoad plugin
SPELLER_DESC=		Spell checking backend

OPTIONS_DEFAULT=	ASPELL
OPTIONS_SUB=		yes

ASPELL_BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
ASPELL_RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
HTTPLOAD_DISTFILES=	httpload2.py:plugins
ISPELL_BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
ISPELL_RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

.include <bsd.port.options.mk>

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py -p ${STAGEDIR}${PREFIX} \
		-d ${STAGEDIR}${DOCSDIR} -i ${STAGEDIR}${DATADIR}/icons -x
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins
.if ${PORT_OPTIONS:MHTTPLOAD}
	${INSTALL_DATA} ${DISTDIR}/httpload2.py \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins/
.endif

.include <bsd.port.mk>
