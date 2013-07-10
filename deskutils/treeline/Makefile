# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	treeline
PORTVERSION=	1.4.1
PORTREVISION=	5
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
USE_PYTHON=	2.5+
NO_BUILD=	yes

DESKTOP_ENTRIES=	"TreeLine" "Structured information storage program" \
			"${DATADIR}/icons/tree/treeline.png" "treeline" \
			"Utility;" false

OPTIONS_DEFINE=		HTTPLOAD PYXML
OPTIONS_SINGLE=		SPELLER
OPTIONS_SINGLE_SPELLER=	ASPELL ISPELL

ASPELL_DESC=	Install with aspell support
HTTPLOAD_DESC=	Install httpLoad plugin
ISPELL_DESC=	Install with ispell support
PYXML_DESC=	Use pythons py-xml instead of textproc/expat2

OPTIONS_DEFAULT=	ASPELL PYXML
OPTIONS_SUB=		yes

ASPELL_BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
ISPELL_BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MPYXML}
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
.endif

.if ${PORT_OPTIONS:MHTTPLOAD}
DISTFILES+=	httpload2.py:plugins
.endif

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py \
	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -x
.if ${PORT_OPTIONS:MHTTPLOAD}
	@${INSTALL_DATA} -d ${PREFIX}/lib/${PORTNAME}/plugins/
	@${INSTALL_DATA} ${DISTDIR}/httpload2.py ${PREFIX}/lib/${PORTNAME}/plugins/
.endif

post-install:
	${RM} ${DOCSDIR}/INSTALL ${DOCSDIR}/LICENSE
.if !${PORT_OPTIONS:MDOCS}
	${RM} ${DOCSDIR}/*
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.mk>
