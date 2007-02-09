# New ports collection makefile for:	wxGlade-devel
# Date created:				30 January 2007
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wxglade
PORTVERSION=	0.4.1
DISTNAME=	${PORTNAME}-${PORTVERSION}cvs
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
PKGNAMESUFFIX=	-devel

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWindows written in Python

CONFLICTS=	wxglade-[0-9]*

WRKSRC=		${WRKDIR}/wxGlade

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_WX=		2.6
WX_COMPS=	python

MAN1=		wxglade.1

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} 'exec ${PYTHON_CMD} \
		${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py \
		"$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	@cd ${WRKSRC} && ${FIND} . \
		\( -name CVS -prune \) -o \
		\( -name docs -prune \) -o \
		\( -name debian -prune \) -o \
		! -name .cvsignore \
		! -name "*.pyc" \
		-print | \
		${CPIO} -dump ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${FIND} . \
		\( -name CVS -prune \) -o \
		! -name .cvsignore \
		! -name "*.pyc" \
		-print | \
		${CPIO} -dump ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/debian/wxglade.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
