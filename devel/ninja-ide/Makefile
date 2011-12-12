# New ports collection makefile for:	ninja-ide
# Date created:		2011-12-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ninja-ide
#PORTVERSION=
DISTVERSION=	2.0-beta2
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/downloads/${PORTNAME}/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A cross-platform integrated development environment (IDE)

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:${PORTSDIR}/www/py-qt4-webkit

FETCH_ARGS=	-Frp

REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},'

SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USE_PYTHON=	2.6-2.7
USE_ZIP=	yes

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/${PORTNAME}.py ${WRKSRC}/ninja_ide/resources.py
	${FIND} ${WRKSRC} -type f \( -name "*.bak" -or -name "*.orig" \) -delete

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	${PYTHON_CMD} -OO -m compileall ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

post-install:
	${RM} -f ${DATADIR}/README ${DATADIR}/COPYING
.if !defined(NOPORTDOCS)
	${MV} ${DATADIR}/ninja_ide/doc ${DOCSDIR}
.else
	${RM} -R ${DATADIR}/ninja_ide/doc
.endif

.include <bsd.port.mk>
