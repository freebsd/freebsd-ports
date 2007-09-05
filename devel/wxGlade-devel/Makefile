# New ports collection makefile for:	wxGlade-devel
# Date created:				30 January 2007
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wxglade
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DISTNAME=	wxGlade-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWindows written in Python

CONFLICTS=	wxglade-[0-9]*

WRKSRC=		${WRKDIR}/wxGlade-${PORTVERSION}

USE_PYTHON=	yes
USE_WX=		2.6+
WX_COMPS=	python

MAN1=		wxglade.1

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} 'exec ${PYTHON_CMD} \
		${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py \
		"$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
.for f in codegen edit_sizers icons res widgets
	${CP} -R ${WRKSRC}/${f} ${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/debian/wxglade.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
