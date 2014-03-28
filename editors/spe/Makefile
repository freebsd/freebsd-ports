# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	SPE
PORTVERSION=	0.8.4.h
PORTREVISION=	6
CATEGORIES=	editors devel python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	python
DISTNAME=	${PORTNAME:L}-${PORTVERSION}-wx2.6.1.0

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Stani's Python Editor

NO_BUILD=	yes

USE_PYTHON=	yes
USE_WX=		2.8
WANT_UNICODE=	yes
WX_COMPS=	python

OPTIONS_DEFINE= ENCRYPTED_DEBUG DOCS EXAMPLES
ENCRYPTED_DEBUG_DESC=	Enable encrypted debug in SPE

REINPLACE_ARGS=	-i.bak -E -e "1s,^(\#!.* )python$$,\1 -S PYTHONPATH=${DATADIR} ${PYTHON_CMD},1"

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}
SPEDOCS=	${DATADIR}/_spe/doc
SPEXAMPLES=	${DATADIR}/_spe/examples
SPESCRIPTS=	spe SPE.py SPE_DEBUG.py

LN_OPTS=	-sf
RM_OPTS=	-R

DESKTOP_ENTRIES=	"SPE (Stani's Python Editor)" \
			"Integrated Python Development Environment" \
			"${DATADIR}/_spe/images/spe.png" \
			"spe" \
			"Development;IDE;Debugger;GUIDesigner;" \
			true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MENCRYPTED_DEBUG}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

post-patch:
	@cd ${WRKSRC}/_spe && ${REINPLACE_CMD} ${SPESCRIPTS} && ${RM} ${RM_OPTS} *.bak

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} _spe ${STAGEDIR}${DATADIR} && \
	${LN} ${LN_OPTS} ${DATADIR}/_spe/spe ${STAGEDIR}${PREFIX}/bin/spe

# documentation
.if ${PORT_OPTIONS:MDOCS}
	${MV} ${STAGEDIR}${SPEDOCS} ${STAGEDIR}${DOCSDIR} && \
	${LN} ${LN_OPTS} ${DOCSDIR} ${STAGEDIR}${SPEDOCS}
.else
	@${RM} ${RM_OPTS} ${STAGEDIR}${SPEDOCS}
.endif
# examples
.if ${PORT_OPTIONS:MEXAMPLES}
	${MV} ${STAGEDIR}${SPEXAMPLES} ${STAGEDIR}${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${STAGEDIR}${SPEXAMPLES}
.else
	@${RM} ${RM_OPTS} ${STAGEDIR}${SPEXAMPLES}
.endif
	cd ${STAGEDIR}${DATADIR}/_spe/ && \
	${CHMOD} ${BINMODE} ${SPESCRIPTS}

.include <bsd.port.mk>
