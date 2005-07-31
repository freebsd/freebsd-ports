# New ports collection makefile for:	treeline
# Date created:		Wed Jul  7 20:50:24 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	treeline
PORTVERSION=	0.12.0
CATEGORIES=	deskutils python
MASTER_SITES=	http://www.bellz.org/treeline/ \
		http://depot.fsck.ch/mirror/distfiles/

MAINTAINER=	ports@fsck.ch
COMMENT=	TreeLine is a structured information storage program

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_ASPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_PYXML)
BUILD_DEPENDS+=	${PYXML}
.else
LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2
.endif

WRKSRC=		${WRKDIR}/TreeLine
USE_QT_VER=	3
USE_PYTHON=	2.3+
NO_BUILD=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} "WITH_ASPELL=yes     install with aspell support"
	@${ECHO_MSG} "                    or"
	@${ECHO_MSG} "WITH_ISPELL=yes     install with ispell support"
	@${ECHO_MSG} "WITH_PYXML=yes      use textproc/py-xml instead of"
	@${ECHO_MSG} "                    textproc/expat2"
	@${ECHO_MSG} ""

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} install.py \
	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -x

post-install:
	${RM} ${DOCSDIR}/INSTALL ${DOCSDIR}/LICENSE
.if defined(NOPORTDOCS)
	${RM} ${DOCSDIR}/*
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.mk>
