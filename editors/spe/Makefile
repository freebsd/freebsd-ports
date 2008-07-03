# New ports collection makefile for:	SPE
# Date created:		2005-10-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	SPE
PORTVERSION=	0.8.4.h
#PORTREVISION=	0
CATEGORIES=	editors devel python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	python
DISTNAME=	${PORTNAME:L}-${PORTVERSION}-wx2.6.1.0

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Stani's Python Editor

NO_BUILD=	yes

USE_PYTHON=	yes
USE_WX=		2.6
WANT_UNICODE=	yes
WX_COMPS=	python

OPTIONS=	ENCRYPTED_DEBUG "Enable encrypted debug in SPE" off

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
post-patch:
	@cd ${WRKSRC}/_spe && ${REINPLACE_CMD} ${SPESCRIPTS} && ${RM} ${RM_OPTS} *.bak

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} _spe ${DATADIR} && \
	${LN} ${LN_OPTS} ${DATADIR}/_spe/spe ${PREFIX}/bin/spe

# documentation
.if !defined (NOPORTDOCS)
	@${MV} ${SPEDOCS} ${DOCSDIR} && \
	${LN} ${LN_OPTS} ${DOCSDIR} ${SPEDOCS}
.else
	@${RM} ${RM_OPTS} ${SPEDOCS}
.endif
# examples
.if !defined (NOPORTEXAMPLES)
	@${MV} ${SPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${SPEXAMPLES}
.else
	@${RM} ${RM_OPTS} ${SPEXAMPLES}
.endif

post-install:
	@cd ${DATADIR}/_spe && \
	${CHMOD} ${BINMODE} ${SPESCRIPTS}

.include <bsd.port.pre.mk>

.if defined(WITH_ENCRYPTED_DEBUG)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.include <bsd.port.post.mk>
