# New ports collection makefile for:	wxGlade
# Date created:				1 May 2003
# Whom:					Michal Pasternak <dotz@irc.pl>
#
# $FreeBSD$

PORTNAME=	wxglade
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWindows written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/${WX_PYTHON_DIR}/wxPython/_wx.py:${PORTSDIR}/x11-toolkits/py-wxPython26

.if defined(WITH_UNICODE)
WX_PYTHON_DIR=	wx-2.6-gtk2-unicode
.else
WX_PYTHON_DIR=	wx-2.6-gtk2-ansi
.endif

WRKSRC=		${WRKDIR}/wxGlade-${PORTVERSION}

USE_PYTHON=	yes

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} 'exec ${PYTHON_CMD} \
		${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py \
		"$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/[^d]* ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif

.include <bsd.port.mk>
