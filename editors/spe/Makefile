# New ports collection makefile for:	SPE
# Date created:		2005-10-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	SPE
PORTVERSION=	0.8.0a
CATEGORIES=	editors devel python
MASTER_SITES=	http://download.berlios.de/python/ \
		${MASTER_SITE_SOURCEFORGE}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/[a-z]$/.&/g}-wx2.6.1.0.-bl2.35

MAINTAINER=	nivit@email.it
COMMENT=	Stani's Python Editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/${WX_PYTHON_DIR}/wxPython/_wx.py:${PORTSDIR}/x11-toolkits/py-wxPython26

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

SPEDOCS=	${PYTHON_SITELIBDIR}/_${PORTNAME:L}/doc
SPEXAMPLES=	${PYTHON_SITELIBDIR}/_${PORTNAME:L}/examples
WINSCRIPT=	spe_wininst.py

LN_OPTS=	-sf
RM_OPTS=	-R

post-install:
# documentation
.if !defined (NOPORTDOCS)
	@${MV} ${SPEDOCS} ${DOCSDIR} && \
	${LN} ${LN_OPTS} ${DOCSDIR} ${SPEDOCS}
.else
	@${RM} ${RM_OPTS} ${SPEDOCS}
.endif
# examples
	@${MV} ${SPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${SPEXAMPLES}
# rm Windows script
	@${RM} ${PREFIX}/bin/${WINSCRIPT}

.include <bsd.port.pre.mk>

.if defined(WITH_UNICODE) && (${OSVERSION} > 500000)
WX_PYTHON_DIR=	wx-2.6-gtk2-unicode
.else
WX_PYTHON_DIR=	wx-2.6-gtk2-ansi
.endif

.include <bsd.port.post.mk>
