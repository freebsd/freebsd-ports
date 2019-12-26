# Created by: Michal Pasternak <dotz@irc.pl>
# $FreeBSD$

PORTNAME=	wxglade
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	SF
DISTNAME=	wxGlade-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWidgets written in Python

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7
USE_WX=		3.0+
WX_COMPS=	python

DESKTOP_ENTRIES="wxGlade" "" "${PYTHON_SITELIBDIR}/wxglade/icons/icon.xpm" \
		"${PORTNAME}" "" true
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		"s|docs_path, 'html'|docs_path, 'doc', 'html'|" ${WRKSRC}/wxglade.py

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} 'exec ${PYTHON_CMD} \
		${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py \
		"$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/wxglade.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "wcodegen codegen edit_sizers icons res widgets" \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME})
	@(cd ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} && \
		${PYTHON_CMD} -m compileall .)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} epydoc.conf *.txt docs/man/*.xml \
		docs/src/*.xml ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}/doc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.* ${STAGEDIR}${DOCSDIR}/doc/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/img
	${INSTALL_DATA} ${WRKSRC}/docs/img/*.* ${STAGEDIR}${DOCSDIR}/doc/img
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/pdf
	${INSTALL_DATA} ${WRKSRC}/docs/pdf/*.pdf ${STAGEDIR}${DOCSDIR}/doc/pdf
	@${LN} -sf ${DOCSDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/docs

.include <bsd.port.mk>
