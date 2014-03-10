# Created by: Michal Pasternak <dotz@irc.pl>
# $FreeBSD$

PORTNAME=	wxglade
PORTVERSION=	0.6.8
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	SF
DISTNAME=	wxGlade-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWidgets written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	yes
# This can be set back to 2.6+ once this port moves to version 0.6.9,
# cf. PR185230.
USE_WX=		2.8+
WX_COMPS=	python

MAN1=		wxglade.1

DESKTOP_ENTRIES="wxGlade" "" "${PYTHON_SITELIBDIR}/wxglade/icons/icon.xpm" \
		"${PORTNAME}" "" true

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		"s|docs_path, 'html'|docs_path, 'doc', 'html'|" ${WRKSRC}/wxglade.py

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} 'exec ${PYTHON_CMD} \
		${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py \
		"$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/wxglade.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
.for f in codegen edit_sizers icons res widgets
	@(cd ${WRKSRC} \
		&& ${COPYTREE_SHARE} ${f} ${PYTHON_SITELIBDIR}/${PORTNAME})
.endfor
	@${PYTHON_CMD} -m compileall ${PYTHON_SITELIBDIR}/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/epydoc.conf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/man/*.xml ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/src/*.xml ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}/doc
	@${MKDIR} ${DOCSDIR}/doc/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.* ${DOCSDIR}/doc/html
	@${MKDIR} ${DOCSDIR}/doc/img
	${INSTALL_DATA} ${WRKSRC}/docs/img/*.* ${DOCSDIR}/doc/img
	@${MKDIR} ${DOCSDIR}/doc/pdf
	${INSTALL_DATA} ${WRKSRC}/docs/pdf/*.pdf ${DOCSDIR}/doc/pdf
	@${LN} -sf ${DOCSDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}/docs
.endif

.include <bsd.port.mk>
