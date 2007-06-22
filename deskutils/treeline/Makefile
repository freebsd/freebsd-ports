# New ports collection makefile for:	treeline
# Date created:		Wed Jul  7 20:50:24 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	treeline
PORTVERSION=	1.0.2
CATEGORIES=	deskutils python
MASTER_SITES=	http://www.bellz.org/treeline/ \
		http://depot.fsck.ch/mirror/distfiles/
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@fsck.ch
COMMENT=	TreeLine is a structured information storage program

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	ASPELL "install with aspell support" off \
		ISPELL "install with ispell support" off \
		PYXML "use pythons py-xml instead of textproc/expat2" on \
		HTTPLOAD "install httpLoad plugin" off \
		TYPESEARCH "install typesearch plugin" off

WRKSRC=		${WRKDIR}/TreeLine
USE_QT_VER=	3
USE_PYTHON=	2.3+
NO_BUILD=	yes

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
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} httpload.py
PLIST_SUB+=	HTTPLOAD=""
.else
PLIST_SUB+=	HTTPLOAD="@comment "
.endif

.if defined(WITH_TYPESEARCH)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} typesearch.py
PLIST_SUB+=	TYPESEARCH=""
.else
PLIST_SUB+=	TYPESEARCH="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py \
	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -x
.if defined(WITH_HTTPLOAD)
	@${INSTALL_DATA} ${DISTDIR}/httpload.py ${PREFIX}/lib/${PORTNAME}/plugins/
.endif
.if defined(WITH_TYPESEARCH)
	@${INSTALL_DATA} ${DISTDIR}/typesearch.py ${PREFIX}/lib/${PORTNAME}/plugins/
.endif

post-install:
	${RM} ${DOCSDIR}/INSTALL ${DOCSDIR}/LICENSE
.if defined(NOPORTDOCS)
	${RM} ${DOCSDIR}/*
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
