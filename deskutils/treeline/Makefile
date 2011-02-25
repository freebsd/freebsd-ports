# New ports collection makefile for:	treeline
# Date created:		Wed Jul  7 20:50:24 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	treeline
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	${MASTER_SITE_BERLIOS:S/$/:treeline/} \
		http://treeline.bellz.org/plugins/:plugins \
		http://depot.fsck.ch/mirror/distfiles/:treeline,plugins
MASTER_SITE_SUBDIR=treeline/:treeline
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:treeline
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	c0rn@o2.pl
COMMENT=	TreeLine is a structured information storage program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

OPTIONS=	ASPELL "install with aspell support" off \
		ISPELL "install with ispell support" off \
		PYXML "use pythons py-xml instead of textproc/expat2" on \
		HTTPLOAD "install httpLoad plugin" off

WRKSRC=		${WRKDIR}/TreeLine
USE_QT_VER=	4
USE_PYTHON=	2.5+
NO_BUILD=	yes
LICENSE=	GPLv2

DESKTOP_ENTRIES=	"TreeLine" "Structured information storage program" \
			"${DATADIR}/icons/tree/treeline.png" "treeline" \
			"Utility;" false

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITHOUT_PYXML)
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
.endif

.if defined(WITH_HTTPLOAD)
DISTFILES+=	httpload2.py:plugins
PLIST_SUB+=	HTTPLOAD=""
.else
PLIST_SUB+=	HTTPLOAD="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py \
	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -x
.if defined(WITH_HTTPLOAD)
	@${INSTALL_DATA} -d ${PREFIX}/lib/${PORTNAME}/plugins/
	@${INSTALL_DATA} ${DISTDIR}/httpload2.py ${PREFIX}/lib/${PORTNAME}/plugins/
.endif

post-install:
	${RM} ${DOCSDIR}/INSTALL ${DOCSDIR}/LICENSE
.if defined(NOPORTDOCS)
	${RM} ${DOCSDIR}/*
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
